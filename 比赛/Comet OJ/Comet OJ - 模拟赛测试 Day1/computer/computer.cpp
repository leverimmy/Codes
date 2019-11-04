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

const int oo = 0x3f3f3f3f;
const int mod = 1e9 + 7;

ll n;

il ll read()
{
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll ksm(ll base, ll power, ll p)
{
	ll res = 1 % p;
	while(power)
	{
		if(power & 1)
			res = res * base % p;
		base = base * base % p; 
		power >>= 1;
	}
	return res;
}

int main()
{
	n = read();
	if(n <= 4)
		printf("%lld", n);
	else if(n % 3 == 0)
		printf("%lld", ksm(3, n / 3, mod));
	else if(n % 3 == 1)
		printf("%lld", ksm(3, n / 3 - 1, mod) * 4 % mod);
	else if(n % 3 == 2)
		printf("%lld", ksm(3, n / 3, mod) * 2 % mod);
	return 0;
}

