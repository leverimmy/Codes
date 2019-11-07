#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define LY(p) freopen (p".in", "r", stdin); freopen (p".out", "w", stdout)
#define LL long long
#define dbl double
#define lf long double
#ifdef WIN32
#define L_L "%I64d"
#else
#define L_L "%lld"
#endif
#define N 410
#define V 410
int n, m, v, c[N][N], w[N][N], f[2][N][V], now, ans;

void upd (int x, int tn, int tx) {
	int nc = c[min (tn, n) - tx + 1][max (tn - n, 0) + tx], nw = w[min (tn, n) - tx + 1][max (tn - n, 0) + tx];

	for (int i = v; i >= 0; i--) {
		if (i >= nc)
			f[now ^ 1][tx][i] = max (f[now][x][i - nc] + nw, f[now ^ 1][tx][i]);
		f[now ^ 1][tx][i] = max (f[now][x][i], f[now ^ 1][tx][i]);
	}		
}

int main()
{
	LY("matrix");
	scanf ("%d %d %d", &n, &m, &v);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf ("%d", &c[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf ("%d", &w[i][j]);

	memset (f, 0xc0, sizeof (f));
	f[now][1][0] = 0;
	if (c[1][1] <= v) f[now][1][ c[1][1] ] = w[1][1];
	for (int t = 1, len, ln, wh; t < n + m - 1; t++) {
		wh = (t < min (n, m)? 0 : t < max (n, m)? 1 : 2);
		if (wh == 0) len = t, ln = len + 1;
		if (wh == 1) len = min (n, m), ln = len;
		if (wh == 2) len = n + m - t, ln = len - 1;
		for (int i = 1; i <= len; i++) {
			upd (i, t + 1, i);
			if (wh == 0 && i < ln)
				upd (i, t + 1, i + 1);
			if (wh == 1) {
				if (n < m && i > 1)
					upd (i, t + 1, i - 1);
				if (n > m && i < ln)
					upd (i, t + 1, i + 1);
			}
			if (wh == 2 && i > 1)
				upd (i, t + 1, i - 1);
		}
		memset (f[now], 0xc0, sizeof (f[now]));
		now ^= 1;
	}
	for (int i = 0; i <= v; i++) ans = max (f[now][1][i], ans);
	printf ("%d", ans);
	return 0;
}
