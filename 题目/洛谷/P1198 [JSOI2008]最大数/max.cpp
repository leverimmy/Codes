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
#define inf 0x3f3f3f3f

using namespace std;

ll n = 1, m, cur, mod;

struct Seg_Tree
{
	ll lc, rc, val;
} t[maxn << 2];

il ll read()
{
	register ll x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void build(ll p, ll l, ll r)
{
	t[p].lc = l, t[p].rc = r;
	if(l == r)
	{
		t[p].val = -inf;
		return;
	}
	ll mid = (t[p].lc + t[p].rc) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	t[p].val = max(t[p << 1].val, t[p << 1 | 1].val);
}

void add(ll p, ll x, ll val)
{
	if(t[p].lc == t[p].rc)
	{
		t[p].val = val % mod;
		return;
	}
	ll mid = (t[p].lc + t[p].rc) >> 1;
	if(x <= mid)
		add(p << 1, x, val);
	else
		add(p << 1 | 1, x, val);
	t[p].val = max(t[p << 1].val, t[p << 1 | 1].val);
}

ll query(ll p, ll l, ll r)
{
	if(l <= t[p].lc && t[p].rc <= r)
		return t[p].val;
	ll mid = (t[p].lc + t[p].rc) >> 1;
	ll res = -inf;
	if(l <= mid)
		res = max(res, query(p << 1, l, r));
	if(mid < r)
		res = max(res, query(p << 1 | 1, l, r));
	return res;
}

int main()
{
	m = read(), mod = read();
	build(1, 1, m);
	for(rgi i = 1; i <= m; i++)
	{
		char cmd[5];
		ll x;
		scanf("%s %lld", cmd, &x);
		if(cmd[0] == 'Q')
		{
			cur = query(1, n - x + 1, n);
			printf("%lld\n", cur);
		}
		else if(cmd[0] == 'A')
		{
			n++;
			add(1, n, (x + cur) % mod);
		}
	}
	return 0;
}

