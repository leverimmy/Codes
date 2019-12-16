#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int mod = 1000000007;
const int N = 4e5 + 10;
const int K = 1e6 + 10;
const int LOG = 30;

int n, k;
ll ans, fac[K] = {1LL}, f[LOG + 10][N], g[LOG + 10];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll qmod(ll a, ll b) {
	ll res = 1 % mod;
	while(b) {
		if(b & 1) res *= a, res %= mod;
		a *= a, a %= mod;
		b >>= 1;
	}
	return res;
}

ll C(ll a, ll b) {
	return fac[b] * qmod(fac[a], mod - 2) % mod * qmod(fac[b - a], mod - 2) % mod;
}

int main() {
	n = read(), k = read();
	
	for(rgi i = 1; i <= k; ++i) fac[i] = fac[i - 1] * i % mod;
	
	for(rgi i = 1; i <= n; ++i) f[1][i] = 1;
	for(rgi i = 1; i <= LOG; ++i)
		for(rgi j = 1; j <= n; ++j)
			for(rgi l = 2; l <= n / j; ++l)
				f[i + 1][l * j] += f[i][j], f[i + 1][j] %= mod;
	
	for(rgi i = 1; i <= LOG; ++i) for(rgi j = 1; j <= n; ++j)
		g[i] += f[i][j];
	
	for(rgi i = 1; i <= LOG && i <= k; ++i)
		ans += g[i] * C(i - 1, k - 1), ans %= mod;
	
	printf("%lld", ans);
	return 0;
}

