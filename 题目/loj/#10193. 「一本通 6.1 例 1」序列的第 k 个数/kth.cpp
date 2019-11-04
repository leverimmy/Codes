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

const int mod = 200907;

int T;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int ksm(int base, int power)
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
	T = read();
	for(; T; --T)
	{
		int a = read(), b = read(), c = read(), k = read();
		if(b - a == c - b)
		{
			int d = b - a;
			printf("%d\n", ((ll)(k - 1) * d + a) % mod);
		}
		if(b / a == c / b)
		{
			int q = b / a;
			printf("%d\n", ((ll)a * ksm(q, k - 1)) % mod);
		}
	}
	return 0;
}

