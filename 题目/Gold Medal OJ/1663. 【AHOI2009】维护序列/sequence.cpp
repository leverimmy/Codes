#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int
#define maxn 100010

using namespace std;

int n, m, mod;
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

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Update(int p)
{
	t[p].val = (t[p << 1].val + t[p << 1 | 1].val) % mod;
}

void Build(int p, int l, int r)
{
	t[p].lc = l, t[p].rc = r;
	if(l == r)
	{
		t[p].val = a[l];
		return;
	}
	int mid = l + r >> 1;
	Build(p << 1, l, mid);
	Build(p << 1 | 1, mid + 1, r);
	Update(p);
}

void Spread(int p)
{
	if(t[p].mul != 1)
	{
		t[p << 1].mul = (t[p].mul * t[p << 1].mul) % mod;
		t[p << 1 | 1].mul = (t[p].mul * t[p << 1 | 1].mul) % mod;
		t[p << 1].add = (t[p].mul * t[p << 1].add) % mod;
		t[p << 1 | 1].add = (t[p].mul * t[p << 1 | 1].add) % mod;
		t[p << 1].val = (t[p].mul * t[p << 1].val) % mod;
		t[p << 1 | 1].val = (t[p].mul * t[p << 1 | 1].val) % mod;
		t[p].mul = 1;
	}
	if(t[p].add != 0)
	{
		t[p << 1].add = (t[p].add + t[p << 1].add) % mod;
		t[p << 1 | 1].add = (t[p].add + t[p << 1 | 1].add) % mod;
		t[p << 1].val = (t[p].add * (t[p << 1].rc - t[p << 1].lc + 1) + t[p << 1].val) % mod;
		t[p << 1 | 1].val = (t[p].add * (t[p << 1 | 1].rc - t[p << 1 | 1].lc + 1) + t[p << 1 | 1].val) % mod;
		t[p].add = 0;
	}
}

void Mul(int p, int l, int r, int val)
{
	if(l <= t[p].lc && t[p].rc <= r)
	{
		t[p].mul = (val * t[p].mul) % mod;
		t[p].add = (val * t[p].add) % mod;
		t[p].val = (val * t[p].val) % mod;
		return;
	}
	Spread(p);
	int mid = t[p].lc + t[p].rc >> 1;
	if(l <= mid)
		Mul(p << 1, l, r, val);
	if(mid < r)
		Mul(p << 1 | 1, l, r, val);
	Update(p);
}

void Add(int p, int l, int r, int val)
{
	if(l <= t[p].lc && t[p].rc <= r)
	{
		t[p].add = (val + t[p].add) % mod;
		t[p].val = (val * (t[p].rc - t[p].lc + 1) + t[p].val) % mod;
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

ll Query(int p, int l, int r)
{
	if(l <= t[p].lc && t[p].rc <= r)
		return t[p].val;
	Spread(p);
	int mid = t[p].lc + t[p].rc >> 1;
	ll res = 0;
	if(l <= mid)
		res = (Query(p << 1, l, r) + res) % mod;
	if(mid < r)
		res = (Query(p << 1 | 1, l, r) + res) % mod;
	return res;
}

int main()
{
	n = read(), mod = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	Build(1, 1, n);
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
			printf("%lld\n", Query(1, l, r));
	}
	return 0;
}

