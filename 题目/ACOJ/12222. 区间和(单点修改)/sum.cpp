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

const int inf = 0x3f3f3f3f;

struct Seg_Tree
{
	int lc, rc, val;
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
	int mid = (t[p].lc + t[p].rc) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	t[p].val = t[p << 1].val + t[p << 1 | 1].val;
}

void add(int p, int x, int val)
{
	if(t[p].lc == t[p].rc)
	{
		t[p].val += val;
		return;
	}
	int mid = (t[p].lc + t[p].rc) >> 1;
	if(x <= mid)
		add(p << 1, x, val);
	else
		add(p << 1 | 1, x, val);
	t[p].val = t[p << 1].val + t[p << 1 | 1].val;
}

int query(int p, int l, int r)
{
	int res = 0;
	if(l <= t[p].lc && t[p].rc <= r)
		return t[p].val;
	int mid = (t[p].lc + t[p].rc) >> 1;
	if(l <= mid)
		res += query(p << 1, l, r);
	if(mid < r)
		res += query(p << 1 | 1, l, r);
	return res;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	build(1, 1, n);
	m = read();
	for(rgi i = 1; i <= m; ++i)
	{
		int op = read();
		if(op == 1)
		{
			int x = read(), val = read();
			add(1, x, val);
		}
		else if(op == 2)
		{
			int l = read(), r = read();
			printf("%d\n", query(1, l, r));
		}
	}
	return 0;
}

