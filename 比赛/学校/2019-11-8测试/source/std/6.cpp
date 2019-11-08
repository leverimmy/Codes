#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005, maxm = 200005;

int n, m, st, ed, d[maxn], z[maxn], q[maxm], edge[maxn], next[maxm], point[maxm], w[maxm]; 

int main()
{
    freopen("6.in", "r", stdin);
    freopen("6.out", "w", stdout);
    while (scanf("%d%d", &n, &m) != EOF)
    {   
        int e = 0; memset(edge, 0, sizeof(edge)); memset(d, 122, sizeof(d)); d[1] = 0;
        for (int i = 1; i <= m; ++i)
        {
            int s, t, k; scanf("%d%d%d", &s, &t, &k);
            point[++e] = t; next[e] = edge[s]; edge[s] = e; w[e] = k;
        }
        ed = 1; z[1] = 1; q[1] = 1;
        for (st = 1; st <= ed; ++st)
        {
            int i = q[st]; 
            for (int b = edge[i]; b; b = next[b])
            {
                int p = point[b];
                if (d[p] > d[i] + w[b])
                {
                    d[p] = d[i] + w[b];
                    if (!z[p]) q[++ed] = p;
                    z[p] = true;
                }
            }
            z[i] = 0;
        }
        printf("%d\n", d[n]);
    }
    return 0;
}
