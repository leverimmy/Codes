#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define LY(p) freopen (p".in", "r", stdin); freopen (p".out", "w", stdout)
#define M 1010
using namespace std;
int n, m, x, y, a[M];
double f[M][M], g[M][M], ans(0);

int main()
{
    LY("inversion10");
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            f[i][j] = a[i] > a[j];
    for (int i = 1; i <= m; i++) {
        scanf ("%d %d", &x, &y);
        if (x == y) continue;
        if (x > y) swap (x, y);
        for (int i = 1; i < x; i++) {
            g[i][x] = (f[i][x] + f[i][y]) / 2;
            g[i][y] = (f[i][x] + f[i][y]) / 2;
        }
        g[x][y] = 0.5;
        for (int i = x + 1; i < y; i++) {
            g[x][i] = (f[x][i] + (1 - f[i][y])) / 2;
            g[i][y] = (f[i][y] + (1 - f[x][i])) / 2;
        }
        for (int i = y + 1; i <= n; i++) {
            g[x][i] = (f[x][i] + f[y][i]) / 2;
            g[y][i] = (f[x][i] + f[y][i]) / 2;
        }
        for (int i = 1; i <= n; i++) {
            if (i < x) f[i][x] = g[i][x];
            else f[x][i] = g[x][i];
            if (i < y) f[i][y] = g[i][y];
            else f[y][i] = g[y][i];
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            ans += f[i][j];
    printf ("%.8lf", ans);
    return 0;
}
