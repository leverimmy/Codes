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
int n, m, d, now(0);
LL f[2][5000][3][55];
const int mo = 1e9 + 7;

void upd (LL &a, LL x) {a += x; if (a >= mo) a %= mo;}

void work (int o, int s, int x, int y) {
	LL nt = f[now][s][x][y];
	if (x) {
		if (s - 2 * o >= 0 && y < o - 1)
			upd (f[now ^ 1][s - 2 * o][x][y + 1], nt * x);
		if (s - o >= 0 && y < o - 1)
			upd (f[now ^ 1][s - o][x - 1][y + 1], nt * x);
		upd (f[now ^ 1][s][x][y], nt * x);
		if (s + o <= 2 * d)
			upd (f[now ^ 1][s + o][x - 1][y], nt * x);
	}
	if (y) {
		if (s - 2 * o >= 0 && y < o - 1)
			upd (f[now ^ 1][s - 2 * o][x][y + 1], nt * y);
		upd (f[now ^ 1][s][x][y], nt * y * 2);
		if (s + 2 * o <= 2 * d)
			upd (f[now ^ 1][s + 2 * o][x][y - 1], nt * y);
	}
}

int main()
{
	LY("wave");
	scanf ("%d %d", &n, &m);
	if (n < 2) {printf ("%d", m == 1? 2 : 0); return 0;}
	
	d = n * (n - 1);
	f[now][-1 + d][1][0] = 2, f[now][-2 + d][2][0] = 1;
	for (int t = 2; t <= n; t++) {
		for (int i = 0; i <= 2 * d; i++)
			for (int j = 0; j <= 2; j++)
				for (int k = 0; k < (t - 1); k++)
					if (f[now][i][j][k])
						work (t, i, j, k), f[now][i][j][k] = 0;
		memset (f[now], 0, sizeof (f[now]));
		now ^= 1;
	}
	printf (L_L, f[now][d + m][0][0]);
	return 0;
}
