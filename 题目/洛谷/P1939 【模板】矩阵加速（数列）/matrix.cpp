#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define il inline
#define ll long long
#define rgi register ll
#define maxn 50
#define maxm 50
#define MOD 1000000007

using namespace std;

ll T;

struct matrix
{
	ll a[20][20];
	matrix()
	{
		for(rgi i = 0; i < 20; ++i)
			for(rgi j = 0; j < 20; ++j)
				a[i][j] = 0;
	}
	void init()
	{
		for(rgi i = 0; i < 20; ++i)
			a[i][i] = 1;
	}
};

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct matrix mul(struct matrix a, struct matrix b)
{
	struct matrix res;
	for(rgi i = 1; i <= 3; ++i)
		for(rgi j = 1; j <= 3; ++j)
			for(rgi k = 1; k <= 3; ++k)
				res.a[i][j] += ((a.a[i][k] % MOD) * (b.a[k][j] % MOD)) % MOD;
	return res;
}

struct matrix ksm(struct matrix base, ll power)
{
	struct matrix res;
	res.init();
	while(power)
	{
		if(power & 1)
			res = mul(res, base);
		base = mul(base, base);
		power >>= 1;
	}
	return res;
}

ll f(ll x)
{
	struct matrix base, res;
	base.a[1][1] = base.a[1][3] = base.a[2][1] = base.a[3][2] = 1;
	res.a[1][1] = res.a[2][1] = res.a[3][1] = 1;
	return mul(ksm(base, x - 3), res).a[1][1] % MOD;
}

int main()
{
	T = read();
	for(rgi i = 1; i <= T; ++i)
	{
		ll n = read();
		if(n <= 3)
			puts("1");
		else
			printf("%lld\n", f(n));
	}
	return 0;
}

