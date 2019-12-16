#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

#define DEBUG 0

const int N = 1e3 + 10;

int T, n, f[N][N], g[N];
char str[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void solve(int x) {
	int l = x, r = x;
	for(; 2 <= l && r <= n - 1 && str[l - 1] == str[r + 1]; l--, r++);
	for(rgi i = 0; i <= x - l; ++i) f[x - i][x + i] = 1;
	
	l = x, r = x + 1;
	if(str[l] == str[r]) {
		for(; 2 <= l && r <= n - 1 && str[l - 1] == str[r + 1]; l--, r++);
		for(rgi i = 0; i <= x - l; ++i) f[x - i][x + 1 + i] = 1;
	}
}

int main() {
//	freopen("testdata.in", "r", stdin);
//	freopen("testdata.out", "w", stdout);
	T = read();
	while(T--) {
		scanf("%s", str + 1);
		n = strlen(str + 1);
		memset(f, 0, sizeof(f));
		memset(g, 0x3f, sizeof(g));
		
		for(rgi i = 1; i <= n; ++i)
			solve(i);	
#if DEBUG
		for(rgi i = 1; i <= n; ++i, puts(""))
			for(rgi j = i; j <= n; ++j, putchar(' '))
				printf("%d", f[i][j]);
#endif
		g[0] = 0;
		for(rgi i = 1; i <= n; ++i)
			for(rgi j = 1; j <= i; ++j) if(f[j][i])
				g[i] = std::min(g[i], g[j - 1] + 1);
		
		printf("%d\n", g[n]);
	}
	return 0;
}
/*
3
racecar
fastcar
aaadbccb

*/ 
