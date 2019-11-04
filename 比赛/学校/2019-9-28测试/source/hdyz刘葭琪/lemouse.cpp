#include <cstdio>
#define re register
int v, c;
template <class T> T read(T& x) {
	x = 0; v = 1; c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) if (c == '-') v = -1;;
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x *= v;
}
template <class T> inline T min(T x, T y) {return x < y ? x : y;}
const int N = 1010, INF = 0x3f3f3f3f;
int n, m, ans, a[N][N], f[N][N][2];
int main() {
	freopen("lemouse.in", "r", stdin);
	freopen("lemouse.out", "w", stdout);
	read(n); read(m);
	for (re int i = 1; i <= n; ++i) {
		for (re int j = 1; j <= m; ++j) {
			read(a[i][j]); f[i][j][0] = f[i][j][1] = a[i][j];
		}
	}
	f[1][1][0] = f[1][1][1] += a[1][2] + a[2][1];
	for (re int i = 2; i <= m; ++i) {
		f[1][i][1] = f[1][i][0] = f[1][i-1][0] + a[2][i] + a[1][i+1];
	}
	for (re int i = 2; i <= n; ++i) {
		f[i][1][0] = f[i][1][1] = f[i-1][1][1] + a[i-1][1] + a[i][2];
	}
	for (re int i = 2; i <= n; ++i) {
		for (re int j = 2; j <= m; ++j) {
			f[i][j][0] = min(f[i][j-1][1] + a[i+1][j], f[i][j-1][0] + a[i+1][j] + a[i-1][j]) + a[i][j];
			f[i][j][1] = min(f[i-1][j][1] + a[i][j-1] + a[i][j+1], f[i-1][j][0] + a[i][j+1]) + a[i][j];
		}
	}
	ans = min(f[n][m][0], f[n][m][1]);
	printf("%d", ans);
	return 0;
}
