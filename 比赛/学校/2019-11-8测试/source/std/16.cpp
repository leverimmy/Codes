#include <bits/stdc++.h>

using namespace std;

const int maxn = 505, maxm = 2005;

int n, m, s[maxm], t[maxm], w[maxm], d[maxn];

int main()
{
    freopen("16.in", "r", stdin);
    freopen("16.out", "w", stdout);
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= m; ++i)
            scanf("%d%d%d", &s[i], &t[i], &w[i]);
        bool ok;
        for (int i = 1; i <= n; ++i)
        {
            ok = false;
            for (int j = 1; j <= m; ++j)
            if (d[s[j]] + w[j] < d[t[j]])
            {
                d[t[j]] = d[s[j]] + w[j];
                ok = true;
            }
            if (!ok) break;
        }
        if (ok) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
