#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 10010
#define maxm 50010

using namespace std;

int n, m, cnt, tot, ans, k, top, idx;
int first[maxn], dfn[maxn], low[maxn], stk[maxn];
int vis[maxn], color[maxn], size[maxn], deg[maxn];

struct edge
{
	int to, _next;
} e[maxm];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v)
{
	e[++cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++idx;
	vis[u] = 1, stk[++top] = u;
	for(rgi i = first[u]; i; i = e[i]._next)
	{
		int v = e[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(vis[v])
			low[u] = min(low[u], dfn[v]);
	}
	if(dfn[u] == low[u])
	{
		vis[u] = 0;
		tot++;
		size[tot]++;
		color[u] = tot;
		while(stk[top] != u)
		{
			int v = stk[top];
			vis[v] = 0;
			size[tot]++;
			color[v] = tot;
			top--;
		}
		top--;
	}
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		Add_Edge(u, v);
	}
	for(rgi i = 1; i <= n; ++i)
		if(!dfn[i])
			tarjan(i);
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = first[i]; j; j = e[j]._next)
			if(color[i] != color[e[j].to])
				deg[color[i]]++;
	for(rgi i = 1; i <= tot; ++i)
		if(!deg[i])
			ans = size[i], k++;
	if(k == 1)
		printf("%d", ans);
	else
		printf("0");
	return 0;
}

