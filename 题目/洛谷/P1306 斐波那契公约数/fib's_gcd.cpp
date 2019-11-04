#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register long long
#define il inline
#define ll long long
#define MOD 100000000

using namespace std;

ll n, m, g;

struct matrix
{
	ll a[2][2];
	matrix()
	{
		for(rgi i = 0; i <= 1; ++i)
			for(rgi j = 0; j <= 1; ++j)
				a[i][j] = 0;
	}
};

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

struct matrix mul(struct matrix a, struct matrix b)
{
	struct matrix res;
	for(rgi i = 0; i <= 1; ++i)
		for(rgi j = 0; j <= 1; ++j)
			for(rgi k = 0; k <= 1; ++k)
				res.a[i][j] += (ll)(a.a[i][k] * b.a[k][j]) % MOD;
	return res;
}

struct matrix ksm(struct matrix base, ll power)
{
	struct matrix res;
	for(rgi i = 0; i <= 1; ++i)
		res.a[i][i] = 1;
	while(power)
	{
		if(power & 1)
			res = mul(res, base);
		base = mul(base, base);
		power >>= 1;
	}
	return res;
}

ll fib(ll x)
{
	struct matrix res;
	res.a[0][0] = res.a[0][1] = res.a[1][0] = 1;
	return ksm(res, x - 1).a[0][0];
}

int main()
{
	n = read(), m = read();
	g = gcd(n, m);
	printf("%lld", fib(g) % MOD);
	return 0;
}

