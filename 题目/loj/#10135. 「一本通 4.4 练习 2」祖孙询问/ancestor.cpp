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
#define maxn 40010
#define maxm 40010

using namespace std;

const int oo = 0x3f3f3f3f;

int n, m, cnt, root;
int lg2[maxn] = { -1}, first[maxn], dep[maxn];
int f[maxn][50];

struct edge
{
	int to, _next;
} e[maxm << 1];

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

void init()
{
	for(rgi i = 1; i <= n; ++i)
		lg2[i] = lg2[i >> 1] + 1;
}

void dfs(int x, int p)
{
	dep[x] = dep[p] + 1;
	f[x][0] = p;
	for(rgi i = 1; i <= lg2[dep[x]]; ++i)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for(rgi i = first[x]; i; i = e[i]._next)
		if(e[i].to != p)
			dfs(e[i].to, x);
}

int lca(int u, int v)
{
	if(dep[u] > dep[v])
		swap(u, v);
	int temp = dep[v] - dep[u];
	for(rgi i = 0; i <= lg2[dep[v]]; ++i)
		if(temp & (1 << i))
			v = f[v][i];
	if(u == v)
		return u;
	for(rgi i = lg2[dep[v]]; i >= 0; --i)
		if(f[u][i] != f[v][i])
		{
			u = f[u][i];
			v = f[v][i];
		}
	return f[u][0];
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		int u = read(), v = read();
		if(v == -1)
			root = u;
		else
		{
			Add_Edge(u, v);
			Add_Edge(v, u);
		}
	}
	init();
	dfs(root, 0);
	m = read();
	for(rgi i = 1; i <= m; ++i)
	{
		int s = read(), t = read();
		int LCA = lca(s, t);
		if(LCA == s)
			puts("1");
		else if(LCA == t)
			puts("2");
		else
			puts("0");
	}
	return 0;
}

