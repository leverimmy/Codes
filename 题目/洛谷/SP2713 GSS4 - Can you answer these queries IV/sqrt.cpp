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

int n, m, kase;
ll a[maxn];

struct Seg_Tree
{
	int lc, rc;
	ll max_val, val;
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
	t[p].max_val = max(t[p << 1].max_val, t[p << 1 | 1].max_val);
}

void Build(int p, int l, int r)
{
	t[p].lc = l, t[p].rc = r;
	if(l == r)
	{
		t[p].max_val = t[p].val = a[l];
		return;
	}
	int mid = l + r >> 1;
	Build(p << 1, l, mid);
	Build(p << 1 | 1, mid + 1, r);
	Update(p);
}

void Clear()
{
	memset(t, 0, sizeof(t));
}

void Modify(int p, int l, int r)
{
	if(t[p].lc == t[p].rc)
	{
		t[p].max_val = sqrt(t[p].max_val);
		t[p].val = sqrt(t[p].val);
		return;
	}
	int mid = t[p].lc + t[p].rc >> 1;
	if(l <= mid)
		Modify(p << 1, l, r);
	if(mid < r)
		Modify(p << 1 | 1, l, r);
	Update(p);
}

ll Query(int p, int l, int r)
{
	if(l <= t[p].lc && t[p].rc <= r)
		return t[p].val;
	int mid = t[p].lc + t[p].rc >> 1;
	ll res = 0;
	if(l <= mid)
		res += Query(p << 1, l, r);
	if(mid < r)
		res += Query(p << 1 | 1, l, r);
	return res;
}

int main()
{
	while(~scanf("%d", &n))
	{
//		Clear();
		printf("Case #%d:\n", ++kase);
		for(rgi i = 1; i <= n; ++i)
			a[i] = read();
		Build(1, 1, n);
		m = read();
		for(rgi i = 1; i <= m; ++i)
		{
			ll op = read(), l = read(), r = read();
			if(l > r)
				swap(l, r);
			if(op == 0)
				Modify(1, l, r);
			else if(op == 1)
				printf("%lld\n", Query(1, l, r));
		}
		puts("");
	}
	return 0;
}

