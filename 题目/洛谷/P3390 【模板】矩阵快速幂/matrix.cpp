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
#define maxn 110

using namespace std;

ll n, k;

struct matrix
{
	ll a[maxn][maxn];
} ans;

il ll read()
{
	register ll x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct matrix mul(struct matrix A, struct matrix B)
{
	struct matrix res;
	for(register ll i = 1; i <= n; ++i)
		for(register ll j = 1; j <= n; ++j)
			res.a[i][j] = 0;
	for(register ll i = 1; i <= n; ++i)
		for(register ll j = 1; j <= n; ++j)
			for(register ll k = 1; k <= n; ++k)
				res.a[i][j] = (res.a[i][j] + A.a[i][k] * B.a[k][j] % MOD) % MOD;
	return res;
}

struct matrix pow(struct matrix base, ll power)
{
	struct matrix res;
	for(register ll i = 1; i <= n; ++i)
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

int main()
{
	//freopen("testdata.in", "r", stdin);
	//freopen("testdata222.out", "w", stdout);
	n = read(), k = read();
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= n; ++j)
			ans.a[i][j] = read();
	ans = pow(ans, k);
	for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= n; ++j)
			printf("%lld ", ans.a[i][j] % MOD);
		puts("");
	}
	return 0;
}

