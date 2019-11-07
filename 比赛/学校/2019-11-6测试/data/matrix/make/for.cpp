#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define LY(p) freopen (p".in", "r", stdin); freopen ("for.out", "w", stdout)
#define LL long long
#define dbl double
#define lf long double
#ifdef WIN32
#define L_L "%I64d"
#else
#define L_L "%lld"
#endif
#define N 210
int n, m, v, c[N][N], w[N][N], now, ans;

void dfs (int x, int y, int v) {
	if (x == n && y == m)
		return (void) (ans = max (now + (v >= c[n][m]? w[n][m] : 0), ans));

	if (y < m) {
		dfs (x, y + 1, v);
		if (v >= c[x][y])
			now += w[x][y], dfs (x, y + 1, v - c[x][y]), now -= w[x][y];
	}
	
	if (x < n) {
		dfs (x + 1, y, v);
		if (v >= c[x][y])
			now += w[x][y], dfs (x + 1, y, v - c[x][y]), now -= w[x][y];
	}
}

int main()
{
	LY("matrix3");
	scanf ("%d %d %d", &n, &m, &v);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf ("%d", &c[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf ("%d", &w[i][j]);

	dfs (1, 1, v);
	printf ("%d", ans);
	return 0;
}
