#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1000 + 10;

int n, m, a[N];
double ans, f[N][N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)	a[i] = read();
	for(rgi i = 1; i <= n; ++i)	for(rgi j = i + 1; j <= n; ++j)
		f[i][j] = a[i] > a[j];
	for(rgi i = 1; i <= m; ++i) {
		ll x, y;
		scanf("%lld %lld", &x, &y);
		if(x == y)	continue;
//		int x = read(), y = read();
		for(rgi j = 1; j <= n; ++j) {
			
//			f[x][j] = f[y][j] = 0.5 * (f[x][j] + f[y][j]);
//			f[j][x] = f[j][y] = 1 - f[x][j];
			
			f[j][x] = f[j][y] = 0.5 * (f[j][x] + f[j][y]);
			f[x][j] = f[y][j] = 1 - f[j][x];
			
		}
		f[x][y] = f[y][x] = 0.5;
	}
	
	for(rgi i = 1; i <= n; ++i)	for(rgi j = i + 1; j <= n; ++j)
		ans += f[i][j];
	
	printf("%.8f", ans);
	return 0;
}
/*
5 10
5 2 4 1 3 
2 5
2 4
1 2
1 4
3 3


*/
