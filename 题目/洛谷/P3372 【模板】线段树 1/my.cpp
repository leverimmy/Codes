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
int a[maxn];

struct Seg_Tree
{
	int lc, rc;
	ll add, val;
} t[maxn << 2];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void build(int p, int l, int r)
{
	t[p].lc = l, t[p].rc = r;
	if(l == r)
	{
		t[p].val = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	t[p].val = t[p << 1].val + t[p << 1 | 1].val;
}

void update(int p)
{
	if(t[p].add)
	{
		t[p << 1].val += (t[p << 1].rc - t[p << 1].lc + 1) * t[p].add;
		t[p << 1 | 1].val += (t[p << 1 | 1].rc - t[p << 1 | 1].lc + 1) * t[p].add;
		t[p << 1].add += t[p].add;
		t[p << 1 | 1].add += t[p].add;
		t[p].add = 0;
	}
}

void add(int p, int l, int r, int val)
{
	if(l <= t[p].lc && t[p].rc <= r)
	{
		t[p].val += val * (t[p].rc - t[p].lc + 1);
		t[p].add += val;
		return;
	}
	update(p);
	int mid = (t[p].lc + t[p].rc) >> 1;
	if(l <= mid)
		add(p << 1, l, r, val);
	if(mid < r)
		add(p << 1 | 1, l, r, val);
	t[p].val = t[p << 1].val + t[p << 1 | 1].val;
}

ll query(int p, int l, int r)
{
	if(l <= t[p].lc && t[p].rc <= r)
		return t[p].val;
	update(p);
	int mid = (t[p].lc + t[p].rc) >> 1;
	ll res = 0;
	if(l <= mid)
		res += query(p << 1, l, r);
	if(mid < r)
		res += query(p << 1 | 1, l, r);
	return res;
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	build(1, 1, n);
	for(rgi i = 1; i <= m; ++i)
	{
		int op = read();
		if(op == 1)
		{
			int l = read(), r = read(), val = read();
			add(1, l, r, val);
		}
		else if(op == 2)
		{
			int l = read(), r = read();
			printf("%lld\n", query(1, l, r));
		}
	}
	return 0;
}
