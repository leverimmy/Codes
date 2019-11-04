#include <iostream>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 5;
int n, F, p[maxn];

template<class T>
inline T read(T &x) {
    x = 0; int w = 1, ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') w = -1;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - 48;
    return x *= w;
}

namespace pt30 {
    void solve() {
        bool flag = true; int ans = 0;
        for (int a = 1; a <= n; a++) {
            for (int len = 1; len <= n; len++) {
                if (a + len * 2 + F - 1 > n) continue; bool flag1 = false;
                for (int j = 0; j < len; j++) if (p[a + j] != p[a + len + F + j]) {flag1 = true; break;}
                if (!flag1) ans++;
            }
        }
        printf("%d\n", ans);
    }
}

namespace pt60 {
    struct Node {int l, r, sum, siz;}z[maxn << 2];

    int quick_pow(int a, int b, int mod) {
        int ans = 1;
        for (; b; b >>= 1, a = a * a % mod) if (b & 1) ans = ans * a % mod;
        return ans % mod;
    }

    void build(int rt, int l, int r) {
        z[rt].l = l, z[rt].r = r;
        if (l == r) {
            z[rt].sum = p[l]; z[rt].siz = 1;
            return ;
        }
        int mid = (l + r) >> 1;
        build(rt << 1, l, mid), build(rt << 1 | 1, mid + 1, r);
        z[rt].siz = z[rt << 1].siz + z[rt << 1 | 1].siz;
        z[rt].sum = (1ll * z[rt << 1].sum * quick_pow(10, z[rt << 1 | 1].siz, 19260817) + z[rt << 1 | 1].sum) % 19260817;
    }

    int query(int rt, int l, int r) {
        if (z[rt].l == l && z[rt].r == r) return z[rt].sum;
        int mid = (z[rt].l + z[rt].r) >> 1;
        if (r <= mid) return query(rt << 1, l, r);
        if (l > mid) return query(rt << 1 | 1, l, r);
        return (1ll * query(rt << 1, l, mid) * quick_pow(10, (r - mid), 19260817) + query(rt << 1 | 1, mid + 1, r)) % 19260817;
    }

    void solve() {
        build(1, 1, n); int ans = 0;
        for (int a = 1; a <= n; a++) {
            for (int len = 1; len <= n; len++) {
                if (a + len * 2 + F - 1 > n) continue;
                if (query(1, a, a + len - 1) == query(1, a + len + F, a + len * 2 + F - 1)) ans++;
            }
        }
        printf("%d\n", ans);
    }
}

int main() {
    freopen("weapon.in", "r", stdin);
    freopen("weapon.out", "w", stdout)
    read(n), read(F);
    for (int i = 1; i <= n; i++) read(p[i]);
    if (n <= 100) {pt30::solve(); return 0;}
    if (n <= 1000) {pt60::solve(); return 0;}
    return 0;
}
