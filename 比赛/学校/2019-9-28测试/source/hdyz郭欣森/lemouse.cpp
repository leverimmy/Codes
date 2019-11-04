#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

inline int read() {
    int op = 1, a = 0; char c = getchar();
    for (; c < '0' || c > '9'; c = getchar()) if (c == '-') op = -1;
    for (; c >= '0' && c <= '9'; c = getchar()) a = a * 10 + c - '0';
    return op * a;
}

int n, m;

namespace pts_100 {
    const int maxn = 1005;
    int a[maxn][maxn], f[maxn][maxn];

    void main() {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                a[i][j] = read();
        memset(f, 0x3f, sizeof f);
        f[1][1] = a[1][1] + a[1][2] + a[2][1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i - 1 >= 1) f[i][j] = min(f[i][j], f[i - 1][j] + a[i][j] + a[i][j + 1] + a[i + 1][j]);
                if (j - 1 >= 1) f[i][j] = min(f[i][j], f[i][j - 1] + a[i][j] + a[i][j + 1] + a[i + 1][j]);
            }
        }
        cout << f[n][m] << '\n';
    }
}

int main() {
    freopen("lemouse.in", "r", stdin);
    freopen("lemouse.out", "w", stdout);
    n = read(), m = read();
    pts_100::main();
    return 0;
}