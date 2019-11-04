#include <cstdio>
#include <algorithm>
#include <cmath>
#define maxn 500010
#define maxm 600020
#define rgi register int
#define il inline

using namespace std;

int n, m, q, cnt, idx, ans;
int is_cut[maxn], dfn[maxn], low[maxn], first[maxn];

struct edge
{
    int to, _next;
} e[maxm];

void Add_Edge(int u, int v)
{
    cnt++;
    e[cnt].to = v;
    e[cnt]._next = first[u];
    first[u] = cnt;
}

void dfs(int u, int p)
{
    int ch = 0;
    dfn[u] = low[u] = ++idx;
    for(rgi i = first[u]; i; i = e[i]._next)
    {
        int v = e[i].to;
        if(!dfn[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u] && u != p)
                is_cut[u] = 1;			  
            if(u == p)					  
                ch++;
        }
        low[u] = min(low[u], dfn[v]);
    }
    if(ch >= 2 && u == p)
        is_cut[u] = 1;
}

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d %d", &n, &m);
    for(rgi i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        Add_Edge(x, y);
        Add_Edge(y, x);
    }
    for(rgi i = 1; i <= n; i++)
        if(!dfn[i])
            dfs(i, i);
    for(rgi i = 1; i <= n; i++)
        if(is_cut[i])
            ans++;
    printf("%d\n", ans);
    return 0;
}

