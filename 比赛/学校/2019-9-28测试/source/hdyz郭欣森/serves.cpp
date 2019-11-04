#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

inline int read() {
    int op = 1, a = 0; char c = getchar();
    for (; c < '0' || c > '9'; c = getchar()) if (c == '-') op = -1;
    for (; c >= '0' && c <= '9'; c = getchar()) a = a * 10 + c - '0';
    return op * a;
}

const int maxn = 30005;
const int maxm = maxn * 5;
int n, m;
int r[maxn];
int cnt, head[maxn];
struct Edge {int w, to, nxt;} e[maxm << 1];
inline void add_edge(int u, int v, int w) {e[++cnt] = (Edge) {w, v, head[u]}; head[u] = cnt;}

namespace pts_40 {
    struct node {
        int d, s;
        bool operator < (const node& rhs) const {return d > rhs.d;}
    };
    int dis[maxn];
    bool vis[maxn];
    void Dijkstra(int s) {
        priority_queue<node> q;
        memset(dis, 0x3f, sizeof dis); memset(vis, 0, sizeof vis);
        dis[s] = 0; q.push((node) {0, s});
        for (; !q.empty(); ) {
            int u = q.top().s; q.pop();
            if (vis[u]) continue; vis[u] = 1;
            for (int i = head[u]; i; i = e[i].nxt) {
                int v = e[i].to;
                if (dis[v] > dis[u] + e[i].w) {
                    dis[v] = dis[u] + e[i].w;
                    q.push((node) {dis[v], v});
                }
            }
        }
    }
    struct Calc {
        int dis, r, id;
        bool operator < (const Calc& rhs) const {
            if (dis == rhs.dis) return r > rhs.r;
            else return dis < rhs.dis;
        }
    } cal[maxn];
    int ans = 0;
    void main() {
        for (int i = 1; i <= n; i++) {
            Dijkstra(i);
            for (int j = 1; j <= n; j++)
                cal[j].r = r[j], cal[j].id = j, cal[j].dis = dis[j];
            sort(cal + 1, cal + n + 1);
            for (int j = 1, max_r = 0; j <= n; j++) {
                if (j == i) continue;
                if (cal[j].r >= max_r) {
                    max_r = cal[j].r;
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    freopen("serves.in", "r", stdin);
    freopen("serves.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i++) r[i] = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        add_edge(u, v, w), add_edge(v, u, w);
    }
    pts_40::main();
    return 0;
}