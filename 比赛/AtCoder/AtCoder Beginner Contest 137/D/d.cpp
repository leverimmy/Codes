#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 100000 + 10;

int n, m, ans;
int a[N];

struct GIVE
{
	int a, b;
} p[N];

struct Seg_Tree
{
	int lc, rc;
	ll add, val;
	Seg_Tree()
	{
		add = 0;
	}
} t[N << 2];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Update(int p)
{
	t[p].val = max(t[p << 1].val, t[p << 1 | 1].val);
}

void Build(int p, int l, int r)
{
	t[p].lc = l, t[p].rc = r;
	if(l == r)
	{
		t[p].val = a[l];
		return ;
	}
	int mid = l + r >> 1;
	Build(p << 1, l, mid);
	Build(p << 1 | 1, mid + 1, r);
	Update(p);
}

void Spread(int p)
{
	if(t[p].add != 0)
	{
		t[p << 1].add += t[p].add;
		t[p << 1 | 1].add += t[p].add;
		t[p << 1].val += t[p].add * (t[p << 1].rc - t[p << 1].lc + 1);
		t[p << 1 | 1].val += t[p].add * (t[p << 1 | 1].rc - t[p << 1 | 1].lc + 1);
		t[p].add = 0;
	}
}

void Add(int p, int l, int r, int val)
{
	if(l <= t[p].lc && t[p].rc <= r)
	{
		t[p].add += val;
		t[p].val += val * (t[p].rc - t[p].lc + 1);
		return;
	}
	Spread(p);
	int mid = t[p].lc + t[p].rc >> 1;
	if(l <= mid)
		Add(p << 1, l, r, val);
	if(mid < r)
		Add(p << 1 | 1, l, r, val);
	Update(p);
}

int Query(int p, int l, int r)
{
	if(l <= t[p].lc && t[p].rc <= r)
		return t[p].val;
	Spread(p);
	int mid = t[p].lc + t[p].rc >> 1;
	int res = -oo;
	if(l <= mid)
		res = max(res, Query(p << 1, l, r));
	if(mid < r)
		res = max(res, Query(p << 1 | 1, l, r));
	return res;
}

bool cmp(struct GIVE A, struct GIVE B)
{
	if(A.b == B.b)
		return A.a < B.a;
	return A.b > B.b;
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
	{
		p[i].a = read();
		p[i].b = read();
	}
	sort(p + 1, p + n + 1, cmp);
	for(rgi i = 1; i <= n; ++i)
		a[i] = i;
	Build(1, 1, n);
	for(rgi i = 1; i <= n; ++i)
	{
		if(m - p[i].a + 1 < 1)
			continue;
		int maxn = Query(1, 1, m - p[i].a + 1);
		if(maxn <= 0)
			continue;
		ans += p[i].b;
		Add(1, maxn, maxn, -oo);
	}
	printf("%d", ans);
	return 0;
}

