#include <cstdio>
#include <algorithm>
using namespace std;

struct node{int s, t, w;};
node a[100005];
int n, m, ans, f[10005];

bool cmp(node a, node b) { return a.w < b.w; }

int find(int i)
{
    if (f[i] != i) f[i] = find(f[i]);
    return f[i];
}

int main()
{
    freopen("5.in", "r", stdin);
    freopen("5.out", "w", stdout);
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 1; i <= m; ++i) scanf("%d%d%d", &a[i].s, &a[i].t, &a[i].w);
        sort(a + 1, a + 1 + m, cmp); ans = 0;
        for (int i = 1; i <= n; ++i) f[i] = i;
        for (int i = 1; i <= m; ++i)
        if (find(a[i].s) != find(a[i].t)) 
        {
            f[f[a[i].s]] = f[a[i].t];
            ans += a[i].w;
        }
        printf("%d\n", ans);
    }  
    return 0;   
}
