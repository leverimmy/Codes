#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define rgl register long long
#define il inline
#define ll long long

using namespace std;

const ll mod = 100003LL;

ll n, m;

il ll read()
{
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll ksm(ll base, ll power)
{
	ll res = 1LL % mod;
	while(power)
	{
		if(power & 1LL)
			res = res * base % mod;
		base = base * base % mod;
		power >>= 1LL;
	}
	return res;
}

int main()
{
	m = read(), n = read();
	printf("%lld", (ksm(m, n) - m * ksm(m - 1LL, n - 1LL) % mod + mod) % mod);
	return 0;
}

