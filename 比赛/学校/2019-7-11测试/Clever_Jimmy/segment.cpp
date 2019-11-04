#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define il inline
#define ll long long
#define rgi register ll
#define maxn (160010 << 1)
#define MAXN (160010 << 1)

using namespace std;

ll T, N, tot;
ll l[maxn], r[maxn];
ll c_left[maxn << 1], c_right[maxn << 1];

ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void init()
{
	tot = 0;
	for(rgi i = 0; i < maxn + MAXN; ++i)
		l[i] = r[i] = c_left[i] = c_right[i] = 0;
}

void add_left(ll x, ll val)
{
	for(; x <= maxn + MAXN - 1; x += x & -x)
		c_left[x] += val;
}

ll query_left(ll x)
{
	ll res = 0;
	for(; x; x -= x & -x)
		res += c_left[x];
	return res;
}

void add_right(ll x, ll val)
{
	for(; x <= maxn + MAXN - 1; x += x & -x)
		c_right[x] += val;
}

ll query_right(ll x)
{
	ll res = 0;
	for(; x; x -= x & -x)
		res += c_right[x];
	return res;
}

int main()
{
	freopen("segment.in", "r", stdin);
	freopen("segment.out", "w", stdout);
	T = read();
	for(rgi kase = 1; kase <= T; ++kase)
	{
		N = read();
		init();
		printf("Case #%lld:\n", kase);
		for(rgi i = 1; i <= N; ++i)
		{
			ll x = read();
			ll y = read();
			if(x == 0)
			{
				tot++;
				l[tot] = y + MAXN;
				r[tot] = y + tot + MAXN;
				printf("%lld\n", query_right(y + tot + MAXN) - query_left(y - 1 + MAXN));
				add_left(y + MAXN, 1);
				add_right(y + tot + MAXN, 1);
			}
			else if(x == 1)
			{
				add_left(l[y], -1);
				add_right(r[y], -1);
			}
		}
	}
	return 0;
}

