#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#define il inline
#define ll long long
#define rgi register int

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, m, cnt, idx, top, tot;
int first[N], max_val[N], f[N], instk[N], stk[N], low[N], dfn[N], belong[N], U[N], V[N];

struct edge
{
	int to, _next;
} e[M << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void Add_Edge(int u, int v)
{
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++idx;
	instk[u] = 1, stk[++top] = u;
	for(rgi i = first[u]; ~i; i = e[i]._next)
	{
		int v = e[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(instk[v])
			low[u] = min(low[u], dfn[v]);
	}
	if(dfn[u] == low[u])
	{
		tot++;
		while(stk[top] != u)
		{
			instk[stk[top]] = 0;
			belong[stk[top]] = tot;
			max_val[tot] = max(max_val[tot], stk[top]);
			top--;
		}
		instk[u] = 0, belong[u] = tot;
		max_val[tot] = max(max_val[tot], u), top--;
	}
}

int dfs(int u)
{
	if(f[u])	return f[u];
	int res = max_val[u];
	for(rgi i = first[u]; ~i; i = e[i]._next)
	{
		int v = e[i].to;
		res = max(res, dfs(v));
	}
	return f[u] = res;
}

int main()
{
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i)
	{
		U[i] = read();
		V[i] = read();
		Add_Edge(U[i], V[i]);
	}
	for(rgi i = 1; i <= n; ++i)
		if(!dfn[i])	tarjan(i);
//	for(rgi i = 1; i <= n; ++i)
//		printf("%d : %d %d\n", i, dfn[i], low[i]);
	memset(first, -1, sizeof(first)); cnt = 0;
	for(rgi i = 1; i <= m; ++i)
		if(belong[U[i]] != belong[V[i]])
			Add_Edge(belong[U[i]], belong[V[i]]);
	for(rgi i = 1; i <= tot; ++i)
		if(!f[i])	dfs(i);
	for(rgi i = 1; i <= n; ++i)	printf("%d ", f[belong[i]]);
	return 0;
}
/*
4 3
1 2
2 4
4 3

*/
