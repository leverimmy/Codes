#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 400 + 10;
const int M = 400 + 10;
const int S = 170 + 10;

int n, m, V;
int v[N][M], w[N][M], f[N][M][S];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int dfs(int x, int y, int vol) { //表示到了(i, j)后，还剩vol体积，能达到的最大价值 
	
	if(f[x][y][vol])		return f[x][y][vol];
	
	if(x == n && y == m) {
		if(vol >= v[x][y])
			return w[x][y];
		else
			return 0;
	}
	
	int res = 0;
	if(x < n) {
		if(vol - v[x][y] >= 0)
			res = std::max(res, dfs(x + 1, y, vol - v[x][y]) + w[x][y]);
		res = std::max(res, dfs(x + 1, y, vol));
	}
	if(y < m) {
		if(vol - v[x][y] >= 0)
			res = std::max(res, dfs(x, y + 1, vol - v[x][y]) + w[x][y]);
		res = std::max(res, dfs(x, y + 1, vol));
	}
	
	return f[x][y][vol] = res;
}

int main() {
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	n = read(), m = read(), V = read();
	for(rgi i = 1; i <= n; ++i)	for(rgi j = 1; j <= m; ++j)
		v[i][j] = read();
	for(rgi i = 1; i <= n; ++i)	for(rgi j = 1; j <= m; ++j)
		w[i][j] = read();
	
	printf("%d", dfs(1, 1, V));
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
