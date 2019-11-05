#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 2500 + 10;
const int M = 2500 + 10;

int n, m, ans;
int l[N][M], r[N][M], u[N][M];
int a[N][M], f[N][M];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)	{
		for(rgi j = 1; j <= m; ++j) {
			a[i][j] = read();
			f[i][j] = a[i][j];
			u[i][j] = a[i - 1][j] == 0 ? (u[i - 1][j] + 1) : 0;
			l[i][j] = a[i][j - 1] == 0 ? (l[i][j - 1] + 1) : 0;
			
			if(i == 1)	u[i][j] = 0;
			if(j == 1)	l[i][j] = 0;
			
		}
	}
	for(rgi i = 1; i <= n; ++i)	for(rgi j = 1; j <= m; ++j) {
		if(a[i][j]) {
			int limit = std::min(u[i][j] + 1, l[i][j] + 1);
			f[i][j] = std::min(f[i - 1][j - 1] + 1, limit);
		}
		else
			f[i][j] = 0;
		ans = std::max(ans, f[i][j]);
	}
	
	for(rgi i = 1; i <= n; ++i) for(rgi j = m; j >= 1; --j) {
		f[i][j] = a[i][j];
		r[i][j] = a[i][j + 1] == 0 ? (r[i][j + 1] + 1) : 0;
		
		if(j == m)	r[i][j] = 0;
	}
	
	for(rgi i = 1; i <= n; ++i)	for(rgi j = m; j >= 1; --j) {
		
		if(a[i][j]){
			int limit = std::min(u[i][j] + 1, r[i][j] + 1);
			f[i][j] = std::min(f[i - 1][j + 1] + 1, limit);
		}
		else
			f[i][j] = 0;
		ans = std::max(ans, f[i][j]);
	}
	
	printf("%d", std::max(ans, f[n][1]));
	
	return 0;
}
/*
4 6
0 1 0 1 0 0
0 0 1 0 1 0
1 1 0 0 0 1
0 1 1 0 1 0

*/
