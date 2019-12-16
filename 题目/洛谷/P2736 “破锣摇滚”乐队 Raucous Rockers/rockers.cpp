#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 20 + 10;

int n, t, m;
int len[N], f[N][N][N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read(), t = read(), m = read();
	for(rgi i = 1; i <= n; ++i) len[i] = read();
	for(rgi i = 1; i <= n; ++i) {
		for(rgi j = 0; j <= m; ++j) {
			for(rgi k = 0; k <= t; ++k) {
				f[i][j][k] = f[i - 1][j][k];
				if(k >= len[i])
					f[i][j][k] = std::max(f[i][j][k], f[i - 1][j][k - len[i]] + 1);
				else if(j >= 1 && t >= len[i])
					f[i][j][k] = std::max(f[i][j][k], f[i - 1][j - 1][t - len[i]] + 1);
			}
		}
	} printf("%d", std::max(f[n][m][0], f[n][m - 1][t]));
	return 0;
}

