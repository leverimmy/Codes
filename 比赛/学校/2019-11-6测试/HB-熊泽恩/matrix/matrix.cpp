#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 400 + 10;
const int M = 400 + 10;
const int S = 400 + 10;

int n, m, V, ans;
int v[N][M], w[N][M], f[2][N][S];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
//	freopen("matrix.in", "r", stdin);
//	freopen("matrix.out", "w", stdout);
	n = read(), m = read(), V = read();
	for(rgi i = 1; i <= n; ++i)	for(rgi j = 1; j <= m; ++j)
		v[i][j] = read();
	for(rgi i = 1; i <= n; ++i)	for(rgi j = 1; j <= m; ++j)
		w[i][j] = read();
	
	for(rgi i = 1; i <= n; ++i)	{
		memset(f[i & 1], 0, sizeof(f[i & 1]));
		for(rgi j = 1; j <= m; ++j) for(rgi k = 0; k <= V; ++k){
			f[i & 1][j][k] = f[i & 1 ^ 1][j][k];
			if(j != 1)
				f[i & 1][j][k] = std::max(f[i & 1][j][k], f[i & 1][j - 1][k]);
			if(k >= v[i][j]) {
				f[i & 1][j][k] = std::max(f[i & 1][j][k], f[i & 1 ^ 1][j][k - v[i][j]] + w[i][j]);
				if(j != 1)
					f[i & 1][j][k] = std::max(f[i & 1][j][k], f[i & 1][j - 1][k - v[i][j]] + w[i][j]);
			}
		}
	}
	
	for(rgi j = 0; j <= V; ++j)	ans = std::max(ans, f[n & 1][m][j]);
	
	printf("%d", ans);
	return 0;
}
/*
3 4 5
1 2 1 1
2 3 1 2
3 2 2 2
2 3 4 2
1 4 5 1
10 1 2 1

*/
