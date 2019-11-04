#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
const int maxn = 1e5 + 10;

inline int read() {
    char c = getchar(); int x = 0, f = 1;
    for (; c > '9' || c < '0'; c = getchar()) if (c == '-') f = -1;
    for (; c >='0' && c <='9'; c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
    return x * f;
}

int n, f, l, r, s, ans;
int a[maxn];

void djj () {
    n = read(), f = read();
    for (register int i = 1; i <= n; i ++)
        a[i] = read();
}

void lxy () {
    for (register int len = 1; len * 2 + f <= n; len ++) {
        s = 0, l = 1, r = 1;
        for (; r + len + f <= n; ) {
            if (a[r] == a[r + len + f]) {
                if (r - l + 1 == len) s ++, l ++;
                else r ++;
            }
            else l = r + 1, r ++;
        }
        ans += s;
    }
    printf ("%d\n", ans);
}

void djj_lxy () {
    djj (), lxy ();
}

int main () {
    freopen ("weapon.in", "r", stdin);
    freopen ("weapon.out", "w", stdout);
    djj_lxy ();
}

/*
11 4
1 1 1 4 1 -8 1 1 1 4 1

6
*/
