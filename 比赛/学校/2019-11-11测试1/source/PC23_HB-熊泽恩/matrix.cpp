#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 5e3 + 10;
const int M = 5e3 + 10;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
//	freopen("matrix.in", "r", stdin);
//	freopen("matrix.out", "w", stdout);
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j) {
			a[i][j] = read();
			if(a[i][j])
				pre[i][j] = a[i - 1][j] ? pre[i - 1][j] + 1 : 1;
			else
				pre[i][j] = 0;
		}
	
	
	
	return 0;
}

