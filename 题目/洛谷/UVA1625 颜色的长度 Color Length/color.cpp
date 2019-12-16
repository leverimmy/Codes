#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 5e3 + 10;
const int DELTA = 27;

int T, n, m, a[N], b[N];
int l[3][DELTA], r[3][DELTA], f[N][N], g[N][N];
char A[N], B[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	T = read();
	while(T--) {
		memset(l, 0x3f, sizeof(l));
		memset(r, 0, sizeof(r));
		
		scanf("%s", A + 1); n = strlen(A + 1);
		scanf("%s", B + 1); m = strlen(B + 1);
		for(rgi i = 1; i <= n; ++i) a[i] = A[i] - 'A' + 1;
		for(rgi i = 1; i <= m; ++i) b[i] = B[i] - 'A' + 1;
		for(rgi i = 0; i <= n; ++i) for(rgi j = 0; j <= m; ++j)
			f[i][j] = 0, g[i][j] = oo;
		
		for(rgi i = 1; i <= n; ++i) {
			l[1][a[i]] = std::min(l[1][a[i]], i);
			r[1][a[i]] = std::max(r[1][a[i]], i);
		}
		for(rgi i = 1; i <= m; ++i) {
			l[2][b[i]] = std::min(l[2][b[i]], i);
			r[2][b[i]] = std::max(r[2][b[i]], i);
		}
		
		for(rgi i = 0; i <= n; ++i)
			for(rgi j = 0; j <= m; ++j) {
				if(i > 0) {
					f[i][j] = f[i - 1][j];
					if(i == l[1][a[i]] && j < l[2][a[i]])
						f[i][j]++;
					if(i == r[1][a[i]] && j >= r[2][a[i]])
						f[i][j]--;
				}
				if(j > 0) {
					f[i][j] = f[i][j - 1];
					if(i < l[1][b[j]] && j == l[2][b[j]])
						f[i][j]++;
					if(i >= r[1][b[j]] && j == r[2][b[j]])
						f[i][j]--;
				}
			}
		
		g[0][0] = 0;
		for(rgi i = 0; i <= n; ++i)
			for(rgi j = 0; j <= m; ++j) {
				if(i > 0) g[i][j] = std::min(g[i][j], g[i - 1][j] + f[i - 1][j]);
				if(j > 0) g[i][j] = std::min(g[i][j], g[i][j - 1] + f[i][j - 1]);
			}
		
		printf("%d\n", g[n][m]);
	}
	return 0;
}

