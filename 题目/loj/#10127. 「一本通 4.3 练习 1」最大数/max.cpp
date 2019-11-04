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
#define maxn 200010

using namespace std;

const ll inf = 0x7fffffff;

ll m, p;
ll len, last;

struct Seg_Tree
{
	ll lc, rc;
	ll add, val;
} t[maxn << 2];

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void build(ll p, ll l, ll r)
{
	t[p].lc = l, t[p].rc = r;
	if(l == r)
	{
		t[p].val = 0;
		return;
	}
	ll mid = l + r >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	t[p].val = max(t[p << 1].val, t[p << 1 | 1].val);
}

void update(ll p)
{
	if(t[p].add != 0)
	{
		t[p << 1].add += t[p].add;
		t[p << 1 | 1].add += t[p].add;
		t[p << 1].val += t[p].add * (t[p << 1].rc - t[p << 1 | 1].lc + 1);
		t[p << 1 | 1].val += t[p].add * (t[p << 1 | 1].rc - t[p << 1 | 1].lc + 1);
		t[p].add = 0;
	}
}

void Add(ll p, ll l, ll r, ll val)
{
	if(l <= t[p].lc && t[p].rc <= r)
	{
		t[p].add += val;
		t[p].val += val * (t[p].rc - t[p].lc + 1);
		return;
	}
	update(p);
	ll mid = t[p].lc + t[p].rc >> 1;
	if(l <= mid)
		Add(p << 1, l, r, val);
	if(mid < r)
		Add(p << 1 | 1, l, r, val);
	t[p].val = max(t[p << 1].val, t[p << 1 | 1].val);
}

ll query(ll p, ll l, ll r)
{
	if(l <= t[p].lc && t[p].rc <= r)
		return t[p].val;
	update(p);
	ll mid = t[p].lc + t[p].rc >> 1;
	ll res = -inf;
	if(l <= mid)
		res = max(res, query(p << 1, l, r));
	if(mid < r)
		res = max(res, query(p << 1 | 1, l, r));
	return res;
}

int main()
{
	m = read(), p = read();
	build(1, 1, maxn - 1);
	for(rgi i = 1; i <= m; ++i)
	{
		char cmd[10];
		scanf("%s", cmd);
		if(cmd[0] == 'A')
		{
			ll t = read();
			len++;
			Add(1, len, len, (last + p + t) % p);
		}
		else if(cmd[0] == 'Q')
		{
			ll L = read();
			last = query(1, len - L + 1 , len);
			printf("%lld\n", last);
		}
	}
	return 0;
}

