#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 100 + 10;
const int mod = 1e9 + 7;

int n, ans;
int points[N], val[N], e[N][N];

void dfs(int x, int y) {
	if(val[x] > points[x])						return;
	if(val[y] > points[y])						return;
	if(val[x] + 3 * (n - y + 1) < points[x])	return;
	if(val[y] + 3 * (n - x + 1) < points[y])	return;
	if(x == n) {
//		for(rgi i = 1; i <= n; ++i) {
//			for(rgi j = 1; j <= n; ++j)
//				printf("%d ", e[i][j]);
//			puts("");
//		}
//		puts("");
		ans++;
		ans %= mod;
		return;
	}
	if(y == n + 1) {
		if(val[x] == points[x])
			dfs(x + 1, x + 2);
		return;
	}
	
	val[y] += 3; e[x][y] = 0, e[y][x] = 3;
	dfs(x, y + 1);
	val[y] -= 3; e[x][y] = 3;
	
	val[x] += 3; e[x][y] = 3, e[y][x] = 0;
	dfs(x, y + 1);
	val[x] -= 3; e[x][y] = 0;
	
	val[x] += 1, val[y] += 1; e[x][y] = 1, e[y][x] = 1;
	dfs(x, y + 1);
	val[x] -= 1, val[y] -= 1;
	
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin >> n;
	for(rgi i = 1; i <= n; ++i)	std::cin >> points[i];
	dfs(1, 2);
	std::cout << ans;
	return 0;
}
/*
4
4 3 6 4

3
3 3 3

*/
