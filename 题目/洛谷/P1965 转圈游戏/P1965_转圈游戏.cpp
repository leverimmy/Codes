#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

ll n, m, k, x;
ll step, ans;

il ll read()
{
	register ll x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(ll x)
{
	if(x < 0)    putchar('-'), x = -x;
	if(x > 9)    write(x / 10);
	putchar(x % 10 + 48);
}

ll ksm(ll base, ll power, ll mod)
{
	ll res = 1 % mod;
	while(power)
	{
		if(power & 1)
			res = (res * base) % mod;
		base = (base * base) % mod;
		power >>= 1;
	}
	return res;
}

int main()
{
	n = read(), m = read();
	k = read(), x = read();
	step = ksm(10, k, n);
	ans = (x + m * step) % n;
	write(ans);
	return 0;
}

