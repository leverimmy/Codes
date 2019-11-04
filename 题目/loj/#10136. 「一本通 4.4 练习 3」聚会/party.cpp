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
#define maxn 500010
#define maxm 500010

using namespace std;

int n, m, cnt;
int lg2[maxn] = { -1}, first[maxn], dep[maxn];
int f[maxn][70];

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

il void Add_Edge(int u, int v)
{
	e[++cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

/*
il void init()
{
	for(rgi i = 1; i <= n; ++i)
		lg2[i] = lg2[i >> 1] + 1;
}
*/

il void dfs(int x)
{
	dep[x] = dep[f[x][0]] + 1;
	for(rgi i = 1; i <= 20; ++i)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for(rgi i = first[x]; i; i = e[i]._next)
	{
		if(e[i].to == f[x][0])
			continue;
		f[e[i].to][0] = x;
		dfs(e[i].to);
	}
}

il int lca(int u, int v)
{
	if(dep[u] > dep[v])
		swap(u, v);
	int temp = dep[v] - dep[u];
	for(rgi i = 0; i <= 20; ++i)
		if(temp & (1 << i))
			v = f[v][i];
	if(u == v)
		return u;
	for(rgi i = 20; i >= 0; --i)
		if(f[u][i] != f[v][i])
		{
			u = f[u][i];
			v = f[v][i];
		}
	return f[u][0];
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= n - 1; ++i)
	{
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
//	init();
	dfs(1);
	for(rgi i = 1; i <= m; ++i)
	{
		int a = read(), b = read(), c = read();
		int LCA1 = lca(a, b), LCA2 = lca(b, c), LCA3 = lca(c, a);
		/*
			if(LCA1 == LCA2)
				LCA = LCA3;
			else if(LCA2 == LCA3)
				LCA = LCA1;
			else if(LCA3 == LCA1)
				LCA = LCA2;
			<->
		*/
		printf("%d %d\n", LCA1 ^ LCA2 ^ LCA3, dep[a] + dep[b] + dep[c] - dep[LCA1] - dep[LCA2] - dep[LCA3]);
	}
	return 0;
}

