#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register long long
#define il inline
#define ll long long
#define maxn 100010

using namespace std;

ll n, m, mod;

int a[maxn];

struct Seg_Tree
{
	int lc, rc;
	ll add, mul, val;
	Seg_Tree()
	{
		mul = 1;
	}
} t[maxn << 2];

il ll read()
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
	int mid = l + r >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	t[p].val = (t[p << 1].val + t[p << 1 | 1].val) % mod;
}

void update(int p)
{
	if(t[p].mul != 1)
	{
		t[p << 1].mul = t[p << 1].mul * t[p].mul % mod;
		t[p << 1 | 1].mul = t[p << 1 | 1].mul * t[p].mul % mod;
		t[p << 1].add = t[p << 1].add * t[p].mul % mod;
		t[p << 1 | 1].add = t[p << 1 | 1].add * t[p].mul % mod;
		t[p << 1].val = t[p << 1].val * t[p].mul % mod;
		t[p << 1 | 1].val = t[p << 1 | 1].val * t[p].mul % mod;
		t[p].mul = 1;
	}
	if(t[p].add != 0)
	{
		t[p << 1].add = (t[p << 1].add + t[p].add) % mod;
		t[p << 1 | 1].add = (t[p << 1 | 1].add + t[p].add) % mod;
		t[p << 1].val = (t[p << 1].val + t[p].add * (t[p << 1].rc - t[p << 1].lc + 1)) % mod;
		t[p << 1 | 1].val = (t[p << 1 | 1].val + t[p].add * (t[p << 1 | 1].rc - t[p << 1 | 1].lc + 1)) % mod;
		t[p].add = 0;
	}
}

void Add(int p, int l, int r, int val)
{
	if(l <= t[p].lc && t[p].rc <= r)
	{
		t[p].val = (t[p].val + (t[p].rc - t[p].lc + 1) * val) % mod;
		t[p].add = (t[p].add + val) % mod;
		return;
	}
	update(p);
	int mid = t[p].lc + t[p].rc >> 1;
	if(l <= mid)
		Add(p << 1, l, r, val);
	if(mid < r)
		Add(p << 1 | 1, l, r, val);
	t[p].val = (t[p << 1].val + t[p << 1 | 1].val) % mod;
}

void Mul(int p, int l, int r, int val)
{
	if(l <= t[p].lc && t[p].rc <= r)
	{
		t[p].val = (t[p].val * val) % mod;
		t[p].add = (t[p].add * val) % mod;
		t[p].mul = (t[p].mul * val) % mod;
		return;
	}
	update(p);
	int mid = t[p].lc + t[p].rc >> 1;
	if(l <= mid)
		Mul(p << 1, l, r, val);
	if(mid < r)
		Mul(p << 1 | 1, l, r, val);
	t[p].val = (t[p << 1].val + t[p << 1 | 1].val) % mod;
}

ll query(int p, int l, int r)
{
	if(l <= t[p].lc && t[p].rc <= r)
		return t[p].val;
	update(p);
	int mid = t[p].lc + t[p].rc >> 1;
	ll res = 0;
	if(l <= mid)
		res = (res + query(p << 1, l, r)) % mod;
	if(mid < r)
		res = (res + query(p << 1 | 1, l, r)) % mod;
	return res;
}

int main()
{
	n = read(), mod = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	build(1, 1, n);
	m = read();
	for(rgi i = 1; i <= m; ++i)
	{
		int op = read(), l = read(), r = read();
		if(op == 1)
		{
			int val = read();
			Mul(1, l, r, val);
		}
		else if(op == 2)
		{
			int val = read();
			Add(1, l, r, val);
		}
		else if(op == 3)
			printf("%lld\n", query(1, l, r) % mod);
	}
	return 0;
}

