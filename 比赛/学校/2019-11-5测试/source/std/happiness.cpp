#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 200005
#define INF 1<<30
#define TOP 130

int a[MAXN], wa[MAXN], wb[MAXN], wv[MAXN], c[MAXN], sa[MAXN];

bool cmp(int *o, int x, int y, int l) { return o[x] == o[y] && o[x + l] == o[y + l]; }

void Swap(int *a, int *b, int n)
{
	int t = 0;
	for (int i = 0; i <= MAXN - 1; i++) t = a[i], a[i] = b[i], b[i] = t;
}

void buildSA(int n, int m)
{
    int i, j, k, p;
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[wa[i] = a[i]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--c[wa[i]]] = i;
    for (j = 1, p = 1; p < n; j <<= 1, m = p)
    {
        for (p = 0, i = n - j; i < n; i++) wb[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= j) wb[p++] = sa[i] - j;
        for (i = 0; i < n; i++) wv[i] = wa[wb[i]];
        for (i = 0; i < m; i++) c[i] = 0;
        for (i = 0; i < n; i++) c[wv[i]]++;
        for (i = 1; i < m; i++) c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--c[wv[i]]] = wb[i];
		Swap(wa, wb, n), wa[sa[0]] = 0;
        for (p = 1, i = 1; i < n; i++) wa[sa[i]] = cmp(wb, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
}

int rank[MAXN], height[MAXN], n;
char anss[MAXN];

void Height()
{
    int k = 0;
    for (int i = 1; i <= n; i++) rank[sa[i]] = i;
    for (int i = 0; i < n; height[rank[i++]] = k)
    {
    	k -= k ? 1 : 0;
        for (int j = sa[rank[i] - 1]; a[i + k] == a[j + k]; k++);
    }
}

char s[10005];
int k, num[MAXN], minv[105], maxv[105];

bool check(int o)
{
    for (int i = 1; i <= k; i++) minv[i] = INF, maxv[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        int t = num[sa[i]];
        if (height[i] < o)
        {
            for (int j = 1; j <= k; j++) minv[j] = INF, maxv[j] = 0;
            maxv[t] = sa[i], minv[t] = sa[i];
        }
        else
        {
            int flag = 1;
            maxv[t] = max(maxv[t], sa[i]), minv[t] = min(minv[t], sa[i]);
            for (int j = 1; j <= k; j++) if (maxv[j] - minv[j] < o) flag = 0;
            if (flag) 
			{
				for (int j = sa[i], tot = 1; tot <= o; tot++, j++) anss[tot] = a[j];
				return 1;
			}
        }
    }
    return 0;
}

int t, len, ntop;

void init()
{
	scanf("%d", &k), n = 0, ntop = TOP;
    memset(num, 0, sizeof(num));
    for (int i = 1; i <= k; i++)
    {
        scanf("%s", s), len = strlen(s);
        for (int j = 0; j < len; j++) a[n] = s[j], num[n++] = i;
        a[n++] = ntop++;
    }
    a[--n] = 0, buildSA(n + 1, ntop), Height();
}

int main()
{
	freopen("happiness.in", "r", stdin);
	freopen("happiness.out", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
    	init();    
        int l = 0, r = 10000, ans = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (check(mid)) ans = max(ans, mid), l = mid + 1;
            else r = mid-1;
        }
        printf("%d\n", ans);
        for (int i = 1; i <= ans; i++) printf("%c", anss[i]);
        printf("\n");
    }
    return 0;
}
