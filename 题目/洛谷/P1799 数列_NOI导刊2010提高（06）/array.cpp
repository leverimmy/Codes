#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 1000 + 10;

int n, a[N], f[N][N], ans = -oo;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read();
	for(rgi i = 1; i <= n; ++i)	a[i] = read();
	
	for(rgi i = 1; i <= n; ++i)	for(rgi j = 0; j <= i; ++j) {
		f[i][j] = f[i - 1][j - 1];
		if(a[i] == i - j)
			f[i][j] = std::max(f[i][j], f[i - 1][j] + 1);
		else
			f[i][j] = std::max(f[i][j], f[i - 1][j]);
	}
	
	for(rgi i = 0; i <= n; ++i)	ans = std::max(ans, f[n][i]);
	
	printf("%d", ans);
	
	return 0;
}

