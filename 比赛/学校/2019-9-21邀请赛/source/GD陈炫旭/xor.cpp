#include<cstdio>
#include<cstring>

const int N = 101000, M = 201000;
int hea[N], nex[M], ver[M], edg[M], pt = 0;
void put(int x, int y, int z) {
    ver[++pt] = y, edg[pt] = z;
    nex[pt] = hea[x], hea[x] = pt;
}

bool vis[N];
int val[N];
void dfs(int x) {
    vis[x] = true;
    for (int i = hea[x]; i; i = nex[i]) {
        int &y = ver[i];
        if (vis[y]) continue;
        val[y] = val[x] ^ edg[i];
        dfs(y);
    }
}

int main () {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(vis, 0, sizeof vis);
        memset(val, 0, sizeof val);
        memset(hea, 0, sizeof hea);
        memset(nex, 0, sizeof nex);
        pt = 0;
        int n, m;
        scanf("%d %d", &n, &m);
        ++n;
        int a, b, c;
        for (int i = 1; i <= m; ++i) {
            scanf("%d %d %d", &a, &b, &c);
            put(a, b + 1, c), put(b + 1, a, c);
        }
        for (int i = 1; i <= n; ++i) {
            if (!vis[i])    dfs(i);
        }
        bool fail = false;
        for (int x = 1; x <= n && !fail; ++x) {
            for (int i = hea[x]; i; i = nex[i]) {
                if ((val[x] ^ val[ver[i]]) != edg[i]) {
                    fail = true;
                    break;
                }
            }
        }

        if (fail) {
            puts("No");
        } else {
            puts("Yes");
        }
    }

    return 0;
}