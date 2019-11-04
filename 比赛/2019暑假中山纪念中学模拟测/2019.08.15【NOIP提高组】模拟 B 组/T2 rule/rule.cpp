#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int
#define rgl register ll
#define ull unsigned ll

using namespace std;

const ll N = 700000 + 10;

ll n, tot;
ll max_prime = -1;
ll ans[N] = {1, 1};
ll cnt[N];
ll vis[N], prime[N];

il ll read()
{
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void Get()
{
	for(rgi i = 2; i <= n; ++i)
	{
		if(vis[i])
			continue;
		prime[++tot] = i;
		for(rgi j = i; j <= n / i; ++j)
			vis[i * j] = 1;
	}
}

il void solve()
{
	for(rgl i = 1; i <= tot; ++i)
	{
		ll res = 0, last = n / prime[i];
		while(last)
		{
			res += last;
			last /= prime[i];
		}
		cnt[i] += res * 2;
	}
}

il void Mul(ll str[], ll x)
{
	ll add = 0;
	for(rgl i = 1; i <= str[0]; ++i)
	{
		str[i] *= x;
		str[i] += add;
		add = str[i] / 1000000000;
		str[i] %= 1000000000;
	}
	str[++str[0]] = add;
	while(str[str[0]] >= 1000000000)
	{
		str[str[0] + 1] += str[str[0]] / 1000000000;
		str[str[0]] %= 10000000000;
		str[0]++;
	}
	while(str[str[0]] == 0)
		str[0]--;
}

int main()
{
	n = read();
	Get();
	solve();
	for(int i = 1; i <= tot; ++i)
		Mul(ans, cnt[i] + 1);
	printf("%lld", ans[ans[0]]);
	for(rgl i = ans[0] - 1; i >= 1 ; --i)
		printf("%09lld", ans[i]);
	return 0;
}

