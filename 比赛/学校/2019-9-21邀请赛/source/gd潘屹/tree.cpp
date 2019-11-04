#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAXN 100005
#define MAXM 500005

using namespace std;

struct EDGE {
	int v, w, next;
} edge[MAXN * 2];

struct EDGE1 {
	int u, v, w;
	bool operator < (const EDGE1& x)
		const { return w < x.w; }
} edge1[MAXM];

int n, m, cnt, ans;
int head[MAXN], fa[MAXN];

int find(int x)
{
	if (fa[x] != x)
		return find(fa[x]);
	return x;
}

void add_edge(int u, int v, int w)
{
	cnt++;
	edge[cnt].v = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

void Kruskal()
{
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	sort(edge1 + 1, edge1 + m + 1);
	for (int i = 1, j = 0; i <= m && j < n; i++)
	{
		int fx = find(edge1[i].u), fy = find(edge1[i].v);
		if (fx != fy)
		{
			j++;
			fa[fx] = fy;
			add_edge(edge1[i].u, edge1[i].v, edge1[i].w);
			add_edge(edge1[i].v, edge1[i].u, edge1[i].w);
		}
	}
}

int dfs(int now, int last, int maxl)
{
	ans += maxl;
	for (int i = head[now]; i; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == last)
			continue;
		dfs(v, now, max(maxl, edge[i].w));
	}
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &edge1[i].u, &edge1[i].v, &edge1[i].w);
	Kruskal();
	dfs(1, 0, 0);
	printf("%d", ans);
	return 0;
}
