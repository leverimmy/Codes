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
#define maxn 200010

using namespace std;

int n, m;
int a[maxn];

struct Seg_Tree
{
	int lc, rc, sum, lazy;
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
		t[p].sum = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
}

void update(int p)
{
	if(t[p].lazy != 0)
	{
		t[p << 1].sum = t[p << 1].rc - t[p << 1].lc + 1 - t[p << 1].sum;
		t[p << 1 | 1].sum = t[p << 1 | 1].rc - t[p << 1 | 1].lc + 1 - t[p << 1 | 1].sum;
		t[p << 1].lazy ^= 1;
		t[p << 1 | 1].lazy ^= 1;
		t[p].lazy = 0;
	}
}

void add(int p, int l, int r)
{
	if(l <= t[p].lc && t[p].rc <= r)
	{
		t[p].sum = t[p].rc - t[p].lc + 1 - t[p].sum;
		t[p].lazy ^= 1;
		return;
	}
	update(p);
	int mid = (t[p].lc + t[p].rc) >> 1;
	if(l <= mid)
		add(p << 1, l, r);
	if(mid < r)
		add(p << 1 | 1, l, r);
	t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
}

int query(int p, int l, int r)
{
	if(l <= t[p].lc && t[p].rc <= r)
		return t[p].sum;
	update(p);
	int mid = (t[p].lc + t[p].rc) >> 1;
	int res = 0;
	if(l <= mid)
		res = res + query(p << 1, l, r);
	if(mid < r)
		res = res + query(p << 1 | 1, l, r);
	return res;
}

int main()
{
	n = read(), m = read();
	//for(rgi i = 1; i <= n; ++i)
	//	scanf("%1d", &a[i]);
	build(1, 1, n);
	for(rgi i = 1; i <= m; ++i)
	{
		int op = read();
		if(op == 0)
		{
			int l = read(), r = read();
			add(1, l, r);
		}
		else if(op == 1)
		{
			int l = read(), r = read();
			printf("%d\n", query(1, l, r));
		}
	}
	return 0;
}

