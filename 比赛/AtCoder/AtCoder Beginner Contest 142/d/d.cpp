#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

ll gcd(ll x, ll y)
{
	return !y ? x : gcd(y, x % y);
}

ll is_prime(ll x)
{
	if(x < 1)	return 0;
	for(rgi i = 2; i <= x / i; ++i)
		if(x % i == 0)
			return 0;
	return 1;
}

int main()
{
	ll a, b, g; int ans = 0;
	scanf("%lld %lld", &a, &b);
	g = gcd(a, b);
	for(register long long i = 1; i <= g; ++i)
	{
		if(g % i == 0)
			if(is_prime(i))
				ans++;
	}
	printf("%d", ans);
	return 0;
}
/*
1000000000000 1000000000000

*/
