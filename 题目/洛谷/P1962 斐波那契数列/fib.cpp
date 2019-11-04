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
#define MOD 1000000007

using namespace std;

ll n;

struct matrix
{
	ll a_00, a_01, a_10, a_11;
	matrix()
	{
		a_00 = a_01 = a_10 = a_11 = 0;
	}
};

il ll read()
{
	register ll x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct matrix mul(struct matrix a, struct matrix b)
{
	struct matrix res;
	res.a_00 = (a.a_00 * b.a_00 % MOD + a.a_01 * b.a_10 % MOD) % MOD;
	res.a_01 = (a.a_00 * b.a_01 % MOD + a.a_01 * b.a_11 % MOD) % MOD;
	res.a_10 = (a.a_10 * b.a_00 % MOD + a.a_11 * b.a_10 % MOD) % MOD;
	res.a_11 = (a.a_10 * b.a_01 % MOD + a.a_11 * b.a_11 % MOD) % MOD;
	return res;
}

struct matrix pow(struct matrix x, ll power)
{
	struct matrix res;
	res.a_00 = res.a_01 = res.a_10 = res.a_11 = 1;
	while(power)
	{
		if(power & 1)
			res = mul(res, x);
		x = mul(x, x);
		power >>= 1;
	}
	return res;
}

ll fib(ll x)
{
	struct matrix base;
	base.a_00 = 1, base.a_01 = 1, base.a_10 = 1, base.a_11 = 0;
	return pow(base, x - 1).a_00;
}

int main()
{
	n = read();
	if(n == 1)
		puts("1");
	else
		printf("%lld", fib(n - 1) % MOD);
	return 0;
}

