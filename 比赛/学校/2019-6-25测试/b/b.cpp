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
#define maxn 1000010
#define MOD 100000007

using namespace std;

ll T;
ll a[maxn];

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

//c[i][j]=a[i][1]*b[1][j]+a[i][2]*b[2][j]+...a[i][n]*b[n][j]

struct matrix mul(struct matrix a, struct matrix b)
{
	struct matrix res;
	res.a_00 = (a.a_00 * b.a_00 % MOD + a.a_01 * b.a_10 % MOD) % MOD;
	res.a_01 = (a.a_00 * b.a_01 % MOD + a.a_01 * b.a_11 % MOD) % MOD;
	res.a_10 = (a.a_10 * b.a_00 % MOD + a.a_11 * b.a_10 % MOD) % MOD;
	res.a_11 = (a.a_10 * b.a_01 % MOD + a.a_11 * b.a_11 % MOD) % MOD;
	return res;
}

struct matrix pow(struct matrix x, int power)
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
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	T = read();
	while(T--)
	{
		ll ans = 0;
		ll n = read(), k = read();
		for(register ll i = 1; i <= n; ++i)
			a[i] = read();
		sort(a + 1, a + n + 1);
		if(a[n] > 0 && a[n - 1] >= 0)
//			ans = fibb[k] * a[n - 1] + fibb[k + 1] * a[n];
			ans = fib(k - 1) % MOD * a[n - 1] % MOD + fib(k) % MOD * a[n] % MOD;
		else if(a[n] > 0 && a[n - 1] < 0)
		{
			ll little = a[n - 1], big = a[n];
			ll ttt = ceil((-little) / big);
			if(ttt >= k)
				ans = big;
			else
			{
				little += k % MOD * big % MOD;
				k -= ttt;
//				ans = fibb[k] * a[n - 1] + fibb[k + 1] * a[n];
				ans = fib(k - 1) * a[n - 1] % MOD + fib(k) * a[n] % MOD;
			}
		}
		else
			ans = a[n];
		printf("%lld\n", ans % MOD);
	}
	return 0;
}