#include <bits/stdc++.h>
#define N 100005
#define M 1000005 
using namespace std;

int n, m, tt, top, ans, q[N], point[M], next[M], edge[N], low[N], dfn[N], fa[N];

void dfs(int i)
{
    low[i] = dfn[i] = ++tt; q[++top] = i;
    for (int b = edge[i]; b; b = next[b])
    {
        int p = point[b];
        if (!dfn[p])
        {
            dfs(p); low[i] = min(low[i], low[p]);
        }
        else if (!fa[p])
            low[i] = min(low[i], dfn[p]);
    }
    if (dfn[i] == low[i])
    {
        while (q[top + 1] != i) fa[q[top--]] = i;
        ans++;
    }
}

int main()
{
    freopen("10.in", "r", stdin);
    freopen("10.out", "w", stdout);
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(dfn, 0, sizeof(dfn)); memset(fa, 0, sizeof(fa));
        ans = 0; memset(edge, 0, sizeof(edge));
        for (int j = 1; j <= m; ++j)
        {
            int i; scanf("%d%d", &i, &point[j]);
            next[j] = edge[i]; edge[i] = j;
        }
        for (int i = 1; i <= n; ++i)
        if (!dfn[i]) dfs(i);
        printf("%d\n", ans);
    }
    return 0;
}
