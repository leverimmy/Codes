#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int mod = 998244353;
const int N = 2000 + 10;

ll n, k, ans;
ll a[N], b[N], f[N][N << 1];

il ll read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read(), k = read();
	for(rgl i = 1; i <= n; ++i) a[i] = b[i + 1] = read();
	b[1] = a[n];
	f[0][n] = 1;
	for(rgl i = 1; i <= n; ++i)
		for(rgl j = n - i; j <= n + i; ++j) {
			if(a[i] == b[i]) {
				f[i][j] = f[i - 1][j] * k;
				f[i][j] %= mod;
			}
			else {
				f[i][j] = f[i - 1][j - 1] + f[i - 1][j] * (k - 2) + f[i - 1][j + 1];
				f[i][j] %= mod;
			}
		}
	for(rgl i = n + 1; i <= n << 1; ++i) ans += f[n][i], ans %= mod;
	printf("%I64d", ans);
	return 0;
}

