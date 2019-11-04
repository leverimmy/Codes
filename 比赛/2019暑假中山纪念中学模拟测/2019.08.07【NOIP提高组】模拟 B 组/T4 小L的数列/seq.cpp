#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register ll

using namespace std;

const ll K = 200 + 10;
const ll mod = 998244353;

ll n, k;
ll b[K], f[K];

struct Matrix
{
	ll a[K][K];
} BASE;

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct Matrix Mul(struct Matrix A, struct Matrix B)
{
	struct Matrix res;
	for(rgi i = 1; i <= k; ++i)
		for(rgi j = 1; j <= k; ++j)
			res.a[i][j] = 0;
	for(rgi i = 1; i <= k; ++i)
		for(rgi j = 1; j <= k; ++j)
			for(rgi l = 1; l <= k; ++l)
				res.a[i][j] = (res.a[i][j] + (ll)A.a[i][l] * B.a[l][j]) % (mod - 1);
	return res;
}

struct Matrix ksm(struct Matrix base, ll power)
{
	power--;
	struct Matrix res = base;
	while(power)
	{
		if(power & 1)
			res = Mul(res, base);
		base = Mul(base, base);
		power >>= 1;
	}
	return res;
}

ll qmod(ll a, ll b)
{
	ll res = 1 % mod;
	while(b)
	{
		if(b & 1)
			res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res % mod;
}

int main()
{
//	freopen("seq.in", "r", stdin);
//	freopen("seq.out", "w", stdout);
	n = read(), k = read();
	for(rgi i = 2; i <= k; ++i)
		BASE.a[i][i - 1] = 1;
	for(rgi i = k; i >= 1; --i)
		BASE.a[i][k] = read();
	for(rgi i = 1; i <= k; ++i)
		f[i] = read();
	if(n <= k)
		printf("%lld", f[n]);
	else
	{
		BASE = ksm(BASE, n - k);
		ll ans = 1;
		for(rgi i = 1; i <= k; ++i)
			ans = (ans * qmod(f[i], BASE.a[i][k])) % mod;
		printf("%lld", ans);
	}
	return 0;
}

