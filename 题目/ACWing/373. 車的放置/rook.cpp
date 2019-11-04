#include <iostream>
#include <cstring>
#define rgi register int

using namespace std;

const int N = 500 + 10;
const int M = 2e5 + 10;

int n, m, t, ans;
int cnt, first[N << 1], tmp[N][N], vis[N << 1], match[N << 1];

struct edge {
    int to, _next;
} e[M << 1];

void Add_Edge(int u, int v) {
    e[cnt].to = v;
    e[cnt]._next = first[u];
    first[u] = cnt++;
}

bool Find(int x) {
    for(rgi i = first[x]; ~i; i = e[i]._next) {
        int y = e[i].to;
        if(vis[y])  continue;   vis[y] = 1;
        if(!match[y] || Find(match[y])) {
            match[y] = x;
            return 1;
        }
    }
    return 0;
}

void Hungary() {
    for(rgi i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof(vis));
        if(!match[i])   ans += Find(i);
    }
}

int main() {
    cin >> n >> m >> t;
    memset(first, -1, sizeof(first));
    for(rgi i = 1; i <= t; ++i) {
        int u, v;   cin >> u >> v;
        tmp[u][v] = 1;
    }
    for(rgi i = 1; i <= n; ++i)
        for(rgi j = 1; j <= m; ++j)
            if(tmp[i][j]) continue;
            else    Add_Edge(i, n + j);
    Hungary();
    cout << ans;
    return 0;
}

