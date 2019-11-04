#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
const int maxn = 1010;
const int INF = 1e9;

inline int max (int a, int b) {
    return a > b ? a : b;
}

inline int min (int a, int b) {
    return a < b ? a : b;
}

inline int read() {
    char c = getchar(); int x = 0, f = 1;
    for (; c > '9' || c < '0'; c = getchar()) if (c == '-') f = -1;
    for (; c >='0' && c <='9'; c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
    return x * f;
}

int dp[maxn][maxn][2];
int a[maxn][maxn];
int n, m;

void djj () {
    n = read(), m = read();
    for (register int i = 1; i <= n; i ++)
        for (register int j = 1; j <= m; j ++)
            a[i][j] = read();
    dp[1][1][0] = dp[1][1][1] = a[1][1] + a[1][2] + a[2][1];
    for (register int i = 2; i <= n; i ++)
        dp[i][1][0] = dp[i - 1][1][0] + a[i][2] + a[i + 1][1], dp[i][1][1] = INF;
    for (register int i = 2; i <= m; i ++)
        dp[1][i][1] = dp[1][i - 1][1] + a[2][i] + a[1][i + 1], dp[1][i][0] = INF;
}

void lxy () {
    for (register int i = 2; i <= n; i ++)
        for (register int j = 2; j <= m; j ++) {
            dp[i][j][0] = min (dp[i - 1][j][0] + a[i][j - 1] + a[i][j + 1] + a[i + 1][j], dp[i - 1][j][1] + a[i + 1][j] + a[i][j + 1]);
            dp[i][j][1] = min (dp[i][j - 1][1] + a[i - 1][j] + a[i][j + 1] + a[i + 1][j], dp[i][j - 1][0] + a[i + 1][j] + a[i][j + 1]);
        }
    printf ("%d\n", min (dp[n][m][1], dp[n][m][0]));
    exit (0);
}

void djj_lxy () {
    djj (), lxy ();
}

int main () {
    freopen ("lemouse.in", "r", stdin);
    freopen ("lemouse.out", "w", stdout);
    djj_lxy ();
}

/*
3 9
0 0 1 0 0 0 0 0 1
1 1 1 1 1 1 0 1 0
1 0 0 1 0 0 1 0 0

9
*/
