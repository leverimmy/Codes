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


const int maxn = 100005;
int n, f, p[maxn];

namespace pts_30 {
    void main() {
        int ans = 0;
        for (int i = 1; i <= n; i++) p[i] = read();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i + j * 2 + f - 1 > n) break;
                bool flag = 1;
                for (int k = i; k < i + j; k++)
                    if (p[k] != p[k + j + f]) {flag = 0; break;}
                if (flag) ans++;
            }
        }
        cout << ans << '\n';
    }
}

namespace pts_60 {
    const long long mod = 212370440130137957ll;
    // long long hash[maxn], s[maxn];
    long long hash[maxn], s[maxn];
    void main() {
        for (int i = 1; i <= n; i++) {
            p[i] = read();
            s[i] = s[i - 1] + p[i];
            int tmp = 1;
            hash[i] = hash[i - 1];
            for (int j = 1; j <= 3; j++) {
                tmp *= s[i]; tmp %= mod;
                hash[i] += tmp;
            }
            hash[i] %= mod;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int tp_r = i + j + f + j - 1;
                if (tp_r > n) break;
                long long tmp1 = hash[i + j - 1] - hash[i - 1];
                long long tmp2 = hash[tp_r] - hash[i + j + f - 1];
                if (tmp1 == tmp2) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    freopen("weapon.in", "r", stdin);
    freopen("weapon.out", "w", stdout);
    n = read(), f = read();
    if (n <= 100) pts_30::main();
    else pts_60::main();
    return 0;
}