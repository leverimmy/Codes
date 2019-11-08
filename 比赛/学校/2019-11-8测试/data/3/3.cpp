#include <cstdio>
#include <memory>
#include <algorithm>
using namespace std;

const int maxn = 10010, maxm = 200010;

int n, m, tt, ans, edge[maxn], point[maxm], next[maxm], low[maxn], dfn[maxn];

void dfs(int i, int last)
{
    dfn[i] = low[i] = ++tt;
    for (int b = edge[i]; b; b = next[b])
    if ((b ^ last) != 1)
    {
        int p = point[b];
        if (!(dfn[p]))
        {
            dfs(p, b);
            low[i] = min(low[i], low[p]);
            ans += (low[p] > dfn[i]);
        }
        else low[i] = min(low[i], dfn[p]);
    }
}           

int main()
{
    freopen("3.in", "r", stdin);
    freopen("3.out", "w", stdout);
    while (scanf("%d%d", &n, &m) != EOF)
    {
        int e = 1; ans = 0;
        memset(dfn, 0, (n + 1) * 4); memset(edge, 0, (n + 1) * 4); 
        for (int i = 1; i <= m; ++i)
        {
            int s, t;
            scanf("%d%d", &s, &t);
            point[++e] = t; next[e] = edge[s]; edge[s] = e;
            point[++e] = s; next[e] = edge[t]; edge[t] = e;
        }
        for (int i = 1; i <= n; ++i)
        if (!(dfn[i]))
            dfs(i, 0);
        printf("%d\n", ans); 
    }   
    return 0;   
}
