#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define max(a, b) ((a) > (b) ? (a) : (b))

using std::priority_queue;
const int maxn = 3e4 + 5, INF = 0x3f3f3f3f;
int n, m, tot, R[maxn], head[maxn];

template<class T>
inline T read(T &x) {
    x = 0; int w = 1, ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') w = -1;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - 48;
    return x *= w;
}

struct Edge {int to, val, nxt;}edge[maxn * 10];
void add(int from, int to, int val) {edge[++tot] = (Edge){to, val, head[from]}, head[from] = tot;}

namespace pt40 {
    bool vis[maxn];
    int ans = 0, b[maxn], max_v[maxn], dis[1007][1007];

    struct Node {
        int w, now;
        bool operator < (const Node &rhs) const{return w > rhs.w;}
    };

    struct LI {
        int val, num;
        bool operator < (const LI &rhs) const{return val < rhs.val;}
    }a[1007];

    void dijkstra(int S) {
        for (int i = 1; i <= n; i++) dis[S][i] = INF, vis[i] = false;
        priority_queue<Node>q; q.push((Node){0, S}); dis[S][S] = 0;
        while (!q.empty()) {
            Node x = q.top(); q.pop();
            int u = x.now;
            if (vis[u]) continue; vis[u] = true;
            for (int i = head[u]; i; i = edge[i].nxt) {
                if (dis[S][edge[i].to] > dis[S][u] + edge[i].val) {
                    dis[S][edge[i].to] = dis[S][u] + edge[i].val;
                    q.push((Node){dis[S][edge[i].to], edge[i].to});
                }
            }
        }
    }

    void solve() {
        for (int i = 1; i <= n; i++) dijkstra(i);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) b[j] = a[j].val = dis[i][j], a[j].num = j, max_v[j] = 0;
            std::sort(a + 1, a + n + 1); std::sort(b + 1, b + n + 1);
            for (int j = 1; j <= n; j++) max_v[j] = max(max_v[j- 1], R[a[j].num]);
            for (int j = 1; j <= n; j++) {
                int pos = std::lower_bound(b + 1, b + n + 1, dis[i][j]) - b;
                if (max_v[pos] <= R[j]) ans++;
            }
        }
        printf("%d\n", ans);
    }
}

int main() {
    freopen("serves.in", "r", stdin);
    freopen("serves.out", "w", stdout);
    read(n), read(m); int x, y, z;
    for (int i = 1; i <= n; i++) read(R[i]);
    for (int i = 1; i <= m; i++) {
        read(x), read(y), read(z);
        add(x, y, z), add(y, x, z);
    }
    if (n <= 1000) {pt40::solve(); return 0;}
    return 0;
}
