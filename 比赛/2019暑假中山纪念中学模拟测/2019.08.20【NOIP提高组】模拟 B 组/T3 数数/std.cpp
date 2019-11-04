#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <string>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

using namespace std;

const int MAX_DIGITS = 60;

ll T, A, B, N;

il ll read()
{
	ll f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll f(ll a, ll b, ll c, ll n)
{
	if(!a)
		return b / c * (n + 1);
	if(a >= c || b >= c)
	{
		if(n & 1)
			return f(a % c, b % c, c, n) + (n + 1) / 2 * n * (a / c) + (b / c) * (n + 1);
		else
			return f(a % c, b % c, c, n) + n / 2 * (n + 1) * (a / c) + (b / c) * (n + 1);
	}
	ll m = (a * n + b) / c;
	return n * m - f(c, c - b - 1, a, m - 1);
}

int main()
{
	T = read();
	for(; T; --T)
	{
		A = read(), B = read(), N = read();
		ll ans = 0;
		for(rgl digits = 0; digits <= MAX_DIGITS; ++digits)
			if(B & (1LL << digits))
				ans--;//减去B的重复的贡献
		for(rgl digits = 0; digits <= MAX_DIGITS; ++digits)
			ans = ans + f(A, B, 1LL << digits, N) - f(A, B, 1LL << digits + 1, N) * 2;
		printf("%lld\n", ans);
	}
	return 0;
}

