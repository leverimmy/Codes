#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 5e3 + 10;
const int M = 5e3 + 10;

int n, m, ans = -oo;
int a[N][M], f[N][M];
char tmp[N][M];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)	scanf("%s", tmp[i] + 1);
	for(rgi i = 1; i <= n; ++i)	for(rgi j = 1, len = 0; j <= m; ++j) {
		if(tmp[i][j] - '0')
			len++;
		else
			len = 0;
		f[j][len]++;
	}
	
	for(rgi i = 1, cnt_line = 0; i <= m; ++i, cnt_line = 0) {
		for(rgi j = i; j >= 1; --j) {
			cnt_line += f[i][j];
			ans = std::max(ans, cnt_line * j);
		}
	}
	
	printf("%d", ans);
	
	return 0;
}

