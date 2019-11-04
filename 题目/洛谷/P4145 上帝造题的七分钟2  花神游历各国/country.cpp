#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define il inline
#define ll long long
#define rgi register ll
#define maxn 100010

using namespace std;

ll n, m;
ll a[maxn];

struct Seg_Tree
{
	ll lc, rc;
	ll val, max_val;
} t[maxn << 2];

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Update(ll p)
{
	t[p].val = t[p << 1].val + t[p << 1 | 1].val;
	t[p].max_val = max(t[p << 1].max_val, t[p << 1 | 1].max_val);
}

void Build(ll p, ll l, ll r)
{
	t[p].lc = l, t[p].rc = r;
	if(l == r)
	{
		t[p].val = t[p].max_val = a[l];
		return;
	}
	ll mid = l + r >> 1;
	Build(p << 1, l, mid);
	Build(p << 1 | 1, mid + 1, r);
	Update(p);
}

void Modify(ll p, ll l, ll r)
{
	if(t[p].lc == t[p].rc)
	{
		t[p].max_val = sqrt(t[p].max_val);
		t[p].val = sqrt(t[p].val);
		return;
	}
	ll mid = t[p].lc + t[p].rc >> 1;
	if(l <= mid && t[p << 1].max_val > 1)
		Modify(p << 1, l, r);
	if(mid < r && t[p << 1 | 1].max_val > 1)
		Modify(p << 1 | 1, l, r);
	Update(p);
}

ll Query(ll p, ll l, ll r)
{
	if(l <= t[p].lc && t[p].rc <= r)
		return t[p].val;
	ll mid = t[p].lc + t[p].rc >> 1;
	ll res = 0;
	if(l <= mid)
		res += Query(p << 1, l, r);
	if(mid < r)
		res += Query(p << 1 | 1, l, r);
	return res;
}

int main()
{
	n = read();
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
	return 0;
}

