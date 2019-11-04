#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#define il inline
#define rgi register int
#define ll long long

using namespace std;

const int N = 5e5 + 10;
const int M = 5e5 + 10;

int n, m, in, out;
int U[N], V[N];
int cnt, first[N], ideg[N], odeg[N];
int top, instk[N], stk[N];
int tot, idx, dfn[N], low[N], belong[N];

struct edge
{
	int to, _next;
} e[M << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
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
	n = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i)
	{
		while(scanf("%d", &V[++m]) && V[m])
		{
			U[m] = i;
			Add_Edge(U[m], V[m]);
		} m--;
	}
	for(rgi i = 1; i <= n; ++i)
		if(!dfn[i]) tarjan(i);
	for(rgi i = 1; i <= m; ++i)
		if(belong[U[i]] != belong[V[i]])
		{
			ideg[belong[V[i]]]++;
			odeg[belong[U[i]]]++;
		}
	for(rgi i = 1; i <= tot; ++i)
	{
		if(!ideg[i])	in++;
		if(!odeg[i])	out++;
	}
	if(tot == 1)	puts("1\n0");
	else	printf("%d\n%d", in, max(in, out));
	return 0;
}
/*
5
2 4 3 0
4 5 0
0
0
1 0

*/
