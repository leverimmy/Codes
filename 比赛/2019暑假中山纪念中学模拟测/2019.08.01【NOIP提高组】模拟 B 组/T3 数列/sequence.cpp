#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register ll
#define maxn 50010
#define maxk 1000010

using namespace std;

ll T;
ll a[maxn], s[maxn], siz[maxk];

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
//	freopen("testdata.in", "r", stdin);
//	freopen("std.out", "w", stdout);
	T = read();
	for(; T; T--)
	{
		ll k = read(), n = read();
		ll ans = 0;
		for(rgi i = 0; i < maxk; ++i)
			siz[i] = 0;
		for(rgi i = 0; i < maxn; ++i)
			s[i] = 0;
		for(rgi i = 1; i <= n; ++i)
		{
			a[i] = read();
			s[i] = s[i - 1] + a[i];
		}
		for(rgi i = 1; i <= n; ++i)
		{
			ll cur = s[i] % k;
			siz[cur]++;
		}
		for(rgi i = 0; i < k; ++i)
			ans += siz[i] * (siz[i] - 1) / 2;
		ans += siz[0];
		printf("%lld\n", ans);
	}
	return 0;
}

