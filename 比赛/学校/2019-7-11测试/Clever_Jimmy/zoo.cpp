#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define il inline
#define ll long long
#define rgi register ll
#define maxn 100010
#define maxm 1000010

using namespace std;

ll n, m, ans;
ll a[maxn], p[maxn], num[maxn];

struct node
{
	ll u, v, w;
} e[maxm];

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct node a, struct node b)
{
	return a.w > b.w;
}

void init(ll x)
{
	for(rgi i = 1; i <= x; ++i)
	{
		p[i] = i;
		num[i] = 1;
	}
}

ll find(ll x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

int main()
{
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	n = read(), m = read();
	init(n);
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	for(rgi i = 1; i <= m; ++i)
	{
		e[i].u = read();
		e[i].v = read();
		e[i].w = min(a[e[i].u], a[e[i].v]);
	}
	sort(e + 1, e + m + 1, cmp);
	for(rgi i = 1; i <= m; ++i)
	{
		ll cur_u = e[i].u, cur_v = e[i].v;
		ll pu = find(p[cur_u]);
		ll pv = find(p[cur_v]);
		if(pu != pv)
		{
			ans += num[pu] * num[pv] * e[i].w;
			num[pv] += num[pu];
			p[pu] = pv;
		}
	}
	printf("%lld", 2 * ans);
	return 0;
}

