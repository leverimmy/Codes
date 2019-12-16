#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 10 + 2;
const int STONE = (1 << 13) + 5;

int n, s, a[N << 1], f[N << 1][STONE]; // ith people, j stone(s) left

int dfs(int x, int left) {
	if(x > n * 2) x -= n * 2;
	if(f[x][left] != -1) return f[x][left];
	if(left == 1) {
		if(x & 1) return f[x][left] = 0;
		else	  return f[x][left] = 1;
	}
	if(x & 1) {
		int res = 0;
		for(rgi i = 1; left - i >= 1 && i <= a[x]; ++i)
			res |= dfs(x + 1, left - i);
		return f[x][left] = res;
	}
	else {
		int res = 1;
		for(rgi i = 1; left - i >= 1 && i <= a[x]; ++i)
			res &= dfs(x + 1, left - i);
		return f[x][left] = res;
	}
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	while(scanf("%d", &n) && n) {
		scanf("%d", &s); 
		memset(f, -1, sizeof(f));
		for(rgi i = 1; i <= n << 1; ++i) scanf("%d", &a[i]);
		printf("%d\n", dfs(1, s));
	}
	return 0;
}
/*
1 9 4 4
1 101 4 4
1 100 4 4
3 97 8 7 6 5 4 3
1 3 1 1
0


*/
