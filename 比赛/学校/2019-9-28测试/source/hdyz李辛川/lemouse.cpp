#include <iostream>
#include <cstdio>
#include <cstring>
#define min(a, b) ((a) < (b) ? (a) : (b))

const int maxn = 1005;
int map[maxn][maxn], f[2][maxn][maxn], n, m;

template<class T>
inline T read(T &x) {
    x = 0; int w = 1, ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') w = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - 48; ch = getchar();}
    return x *= w;
}

int main() {
    freopen("lemouse.in", "r", stdin);
    freopen("lemouse.out", "w", stdout);
    memset(f, 0x3f, sizeof(f));
    read(n), read(m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            read(map[i][j]);
    f[0][1][1] = f[1][1][1] = map[1][1] + map[1][2] + map[2][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            f[1][i][j] = min(f[0][i][j - 1], f[1][i][j - 1] + map[i - 1][j]) + map[i + 1][j] + map[i][j + 1];
            f[0][i][j] = min(f[0][i - 1][j] + map[i][j - 1], f[1][i - 1][j]) + map[i + 1][j] + map[i][j + 1];
        }
    }
    printf("%d\n", min(f[0][n][m], f[1][n][m]));
    return 0;
}

