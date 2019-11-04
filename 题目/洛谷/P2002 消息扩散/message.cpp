#pragma GCC ("-W1,--stack=128000000)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int N = 1e5 + 10;
const int M = 5e5 + 10;

int n, m, ans;
int cnt, first[N], U[M], V[M], deg[N];
int idx, tot, dfn[N], low[N], belong[N];
int top, stk[N], instk[N];

struct edge
{
	int to, _next;
} e[M];

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
			belong[stk[top]] = tot;
			instk[stk[top]] = 0;
			top--;
		}
		belong[u] = tot, instk[u] = 0, top--;
	}
}

int main()
{
	freopen("testdata (6).in", "r", stdin);
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i)
	{
		U[i] = read(), V[i] = read();
		if(U[i] == V[i])	continue;
		Add_Edge(U[i], V[i]);
	}
	for(rgi i = 1; i <= n; ++i)
		if(!dfn[i]) tarjan(i);
	for(rgi i = 1; i <= m; ++i)
		if(belong[U[i]] != belong[V[i]])
			deg[belong[V[i]]]++;
	for(rgi i = 1; i <= tot; ++i)
		if(!deg[i])	ans++;
	printf("%d", ans);
	return 0;
}
/*
5 4
1 2
2 1
2 3
5 1

*/
