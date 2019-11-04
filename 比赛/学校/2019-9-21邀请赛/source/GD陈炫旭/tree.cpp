#include<cstdio>
#include<algorithm>

const int N = 101000, M = 510000;

struct Edg {
    int u, v, len;

    bool operator < (Edg b) {
        return len < b.len;
    }
} in[M];

int n;

namespace SF {
    int fa[N];

    void init() {
        for (register int i = 1; i <= n; ++i) {
            fa[i] = i;
        }
    }

    int find(int x) {
        return fa[x] == x ? x : (fa[x] = find(fa[x]));
    }

    void merge(int x, int y) {
        if ((x = find(x)) == (y = find(y))) return;
        fa[x] = y;
    }
}

int hea[N], nex[N << 1], ver[N << 1], edg[N << 1], pt = 0;
void put(int x, int y, int z) {
    ver[++pt] = y, edg[pt] = z;
    nex[pt] = hea[x], hea[x] = pt;
}

inline int max(const int &a, const int &b) {
    return a > b ? a : b;
}

long long ans = 0;
void dfs(const int &x, const int &mx, const int &fa) {
    // printf("DFS:%d %d %d %lld\n", x, fa, mx, ans);
    ans += mx;
    for (int i = hea[x]; i; i = nex[i]) {
        int &y = ver[i];
        if (y != fa)    dfs(y, max(mx, edg[i]), x);
    }
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    int m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &in[i].u, &in[i].v, &in[i].len);
    }

    std::sort(in, in + m);
    SF::init();
    for (int i = 0; i < m; ++i) {
        int &u = in[i].u, &v = in[i].v, &len = in[i].len;
        if (SF::find(u) != SF::find(v)) {
            put(u, v, len), put(v, u, len);
            SF::merge(u, v);
            // printf("\t kruskal:%d %d %d\n", u, v, len);
        }
    }

    dfs(1, 0, 0);
    printf("%lld\n", ans);
    return 0;
}