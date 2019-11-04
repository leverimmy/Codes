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

int n, m, x, k;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int ksm(int base, int power, int mod)
{
	int res = 1 % mod;
	while(power)
	{
		if(power & 1)
			res = (ll)res * base % mod;
		base = (ll)base * base % mod;
		power >>= 1;
	}
	return res;
}

int main()
{
	n = read(), m = read(), k = read(), x = read();
	printf("%d", ((ll)x + m * ksm(10, k, n)) % n);
	return 0;
}

