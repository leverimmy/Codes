#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <string>
#include <bitset>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

using namespace std;

ll T;

il ll read()
{
	rgl f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

/*ll Count(ll x)
{
	ll res = 0;
	while(x)
	{
		res += x & 1;
		x >>= 1;
	}
	return res;
}*/

int main()
{
	T = read();
	for(; T; --T)
	{
		ll A = read(), B = read(), N = read(), ans = 0;
		for(rgl i = 1; i <= N; ++i)
		{
			ll cur = B + i * A;
			ans += (ll)__builtin_popcountl(cur);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

