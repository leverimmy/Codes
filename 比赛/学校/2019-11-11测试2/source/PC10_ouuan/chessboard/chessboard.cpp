#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, k, m;
vector<int> col, save, ans;

struct Query
{
	int type, c, x1, y1, x2, y2;
	Query() {}
	Query(int _type, int _c, int _x1, int _y1, int _x2, int _y2)
	{
		type = _type;
		c = _c;
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
	}
};

vector<Query> q;

struct Modification
{
	bool type;
	int l, r, x;
	Modification(bool _type, int _l, int _r, int _x)
	{
		type = _type;
		l = _l;
		r = _r;
		x = _x;
	}
};

vector<vector<Modification> > mod;

struct SegmentTree
{
#define ls (cur << 1)
#define rs (cur << 1 | 1)
#define mid ((l + r) >> 1)

	vector<set<int> > s;
	
	SegmentTree(int size)
	{
		s.resize(size << 2);
	}
	
	void modify(int cur, int l, int r, int L, int R, int x)
	{
		if (l >= R || r <= L) return;
		if (L <= l && r <= R)
		{
			if (x > 0) s[cur].insert(x);
			else s[cur].erase(-x);
		}
		else
		{
			modify(ls, l, mid, L, R, x);
			modify(rs, mid, r, L, R, x);
		}
	}
	
	void solve(int cur, int l, int r, int x, bool type)
	{
		if (!s[cur].empty()) x = max(x, *s[cur].rbegin());
		if (l == r - 1)
		{
			if ((l & 1) == type) ans[l] = col[x];
			return;
		}
		solve(ls, l, mid, x, type);
		solve(rs, mid, r, x, type);
	}

#undef ls
#undef rs
#undef mid
};

vector<SegmentTree> t;

int main()
{
	freopen("chessboard.in", "r", stdin);
	freopen("chessboard.out", "w", stdout);
	
	scanf("%d%d%d", &n, &k, &m);
	
	t.resize(2, SegmentTree(n + 1));
	col.resize(m + 1, 1);
	mod.resize(n + 2);
	q.resize(m + 1);
	save.resize(1);
	
	for (int i = 1; i <= m; ++i)
	{
		string op;
		cin >> op;
		if (op[0] == 'P')
		{
			q[i].type = 1;
			scanf("%d%d%d%d%d", &col[i], &q[i].x1, &q[i].y1, &q[i].x2, &q[i].y2);
			++q[i].x1;
			++q[i].y1;
			++q[i].x2;
			++q[i].y2;
			q[i].c = i;
		}
		else if (op[0] == 'S')
		{
			q[i].type = 2;
			save.push_back(i);
		}
		else
		{
			int x;
			scanf("%d", &x);
			q[i].type = 3;
			q[i].c = save[x];
		}
	}
	
	for (int i = m; i >= 1; --i)
	{
		if (q[i].type == 3) i = q[i].c;
		else if (q[i].type == 1)
		{
			Query u = q[i];
			mod[u.x1].push_back(Modification((u.x1 + u.y1) & 1, u.y1, u.y2 + 1, u.c));
			mod[u.x2 + 1].push_back(Modification((u.x1 + u.y1) & 1, u.y1, u.y2 + 1, -u.c));
		}
	}
	
	ans.resize(n + 1);
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < mod[i].size(); ++j)
		{
			Modification u = mod[i][j];
			t[u.type].modify(1, 1, n + 1, u.l, u.r, u.x);
		}
		t[0].solve(1, 1, n + 1, 0, i & 1);
		t[1].solve(1, 1, n + 1, 0, (i & 1) ^ 1);
		for (int j = 1; j <= n; ++j) printf("%d ", ans[j]);
		puts("");
	}
	
	return 0;
}
