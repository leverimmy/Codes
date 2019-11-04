#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 100010

using namespace std;

int n, m;

struct Seg_Tree
{
	int lc, rc;
	int add, val;
} t[maxn << 2];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Update(int p)
{
	t[p].val = t[p << 1].val + t[p << 1 | 1].val;
}

void Build(int p, int l, int r)
{
	t[p].lc = l, t[p].rc = r;
	if(l == r)
	{
		t[p].val = 0;
		return;
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

void Modify(int p, int l, int r)
{
	if(l <= t[p].lc && t[p].rc <= r)
	{
		t[p].add++;
		t[p].val++;
		return;
	}
	Spread(p);
	int mid = t[p].lc + t[p].rc >> 1;
	if(l <= mid)
		Modify(p << 1, l, r);
	if(mid < r)
		Modify(p << 1 | 1, l, r);
	Update(p);
}

int Query(int p, int l, int r)
{
	if(l <= t[p].lc && t[p].rc <= r)
		return t[p].val;
	Spread(p);
	int mid = t[p].lc + t[p].rc >> 1;
	int res = 0;
	if(l <= mid)
		res += Query(p << 1, l, r);
	if(mid < r)
		res += Query(p << 1 | 1, l, r);
	return res;
}

int main()
{
	n = read(), m = read();
	Build(1, 1, n);
	for(rgi i = 1; i <= m; ++i)
	{
		int op = read();
		if(op == 1)
		{
			int l = read(), r = read();
			Modify(1, l, r);
		}
		else if(op == 2)
		{
			int x = read();
			printf("%d\n", Query(1, x, x) % 2);
		}
	}
	return 0;
}

