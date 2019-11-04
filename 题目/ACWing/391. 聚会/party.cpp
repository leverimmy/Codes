#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#define rgi register int
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 5e5 + 10;
const int M = 5e5 + 10;

int n, m, cnt;
int first[N], dep[N], f[N][50], lg2[N << 1] = {-1};

struct edge
{
    int to, _next;
} E[M << 1];

il int read()
{
    rgi x = 0, f = 0, ch;
    while(!isdigit(ch = getchar())) f |= ch == '-';
    while(isdigit(ch))  x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

void Add_Edge(int u, int v)
{
    E[cnt].to = v;
    E[cnt]._next = first[u];
    first[u] = cnt++;
}

void dfs(int x, int p)
{
    dep[x] = dep[p] + 1;
    f[x][0] = p;
    for(rgi i = 1; i <= lg2[dep[x]]; ++i)
        f[x][i] = f[f[x][i - 1]][i - 1];
    for(rgi i = first[x]; ~i; i = E[i]._next)
        if(E[i].to != p)
            dfs(E[i].to, x);
}

int lca(int u, int v)
{
    if(dep[u] > dep[v])
        swap(u, v);
    int tmp = dep[v] - dep[u];
    for(rgi i = 0; i <= lg2[dep[v]]; ++i)
        if(tmp & (1 << i))
            v = f[v][i];
    if(u == v)
        return u;
    for(rgi i = lg2[dep[v]]; i >= 0; --i)
        if(f[u][i] != f[v][i])
        {
            u = f[u][i];
            v = f[v][i];
        }
    return f[u][0];
}

int main()
{
    n = read(), m = read();
    memset(first, -1, sizeof(first));
    for(rgi i = 1; i <= n; ++i) lg2[i] = lg2[i >> 1] + 1;
    for(rgi i = 1; i <= n - 1; ++i)
    {
        int u = read(), v = read();
        Add_Edge(u, v);
        Add_Edge(v, u);
    }
    dfs(1, 0);
    for(rgi i = 1; i <= m; ++i)
    {
        int a = read(), b = read(), c = read();
        int d = lca(a, b), _e = lca(b, c), _f = lca(c, a);
        printf("%d %d\n", d ^ _e ^ _f, dep[a] + dep[b] + dep[c] - dep[d] - dep[_e] - dep[_f]);
    }
    return 0;
}
