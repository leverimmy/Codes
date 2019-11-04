#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;
const int maxn = 3e4 + 10;
const int maxm = 3e5 + 10;

inline int read() {
    char c = getchar(); int x = 0, f = 1;
    for (; c > '9' || c < '0'; c = getchar()) if (c == '-') f = -1;
    for (; c >='0' && c <='9'; c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
    return x * f;
}

int dis[maxn], ver[maxm], edge[maxm], nxt[maxm], head[maxn], tot;
int n, m, u, v, w, ans;
bool inq[maxn];
queue <int> q;
int r[maxn];

void add (int u, int v, int w) {
    nxt[++ tot] = head[u], head[u] = tot;
    ver[tot] = v, edge[tot] = w;
}

void spfa (int S) {
    memset (dis, 0x3f, sizeof dis);
    memset (inq, 0, sizeof inq);
    dis[S] = 0, inq[S] = 1;
    q.push (S);
    for (; !q.empty(); ) {
        u = q.front (), q.pop ();
        inq[u] = 0;
        for (register int i = head[u]; i; i = nxt[i]) {
            v = ver[i], w = edge[i];
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!inq[v]) {
                    q.push (v);
                    inq[v] = 1;
                }
            }
        }
    }
}

struct Point {
    int dis, a;
} h[maxn];

bool cmp (Point a, Point b) {
    return a.dis == b.dis ? a.a > b.a : a.dis < b.dis;
}

int s, maxx, cnt_;

void djj () {
    n = read(), m = read();
    for (register int i = 1; i <= n; i ++)
        r[i] = read();
    for (; m; m --) {
        u = read(), v = read(), w = read();
        add (u, v, w), add (v, u, w);
    }
}

void lxy () {
    for (register int i = 1; i <= n; i ++) {
        spfa (i);
        cnt_ = 0;
        for (register int j = 1; j <= n; j ++)
            h[++ cnt_].a = r[j], h[cnt_].dis = dis[j];
        sort (h + 1, h + cnt_ + 1, cmp);
        s = 1, maxx = h[1].a;
        for (register int j = 2; j <= tot; j ++) {
            if (h[j].a >= maxx) s ++, maxx = h[j].a;
        }
        ans += s;
    }
    printf ("%d\n", ans);
}

void djj_lxy () {
    djj (), lxy ();
}

int main () {
    freopen ("serves.in", "r", stdin);
    freopen ("serves.out", "w", stdout);
    djj_lxy ();
}

/*
4 3
2
3
1
1
1 4 30
2 3 20
3 4 20

9
*/
