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

const int oo = 0x3f3f3f3f;

int n;
int cnt, first[N], dep[N];
int f[N][50], w[N][50];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void Add_Edge(int u, int v, int w)
{
	e[cnt].to = v;
	e[cnt]._next = first[u];
	e[cnt].wt = w;
	first[u] = cnt++;
}

void dfs(int x, int p, int weight)
{
	dep[x] = dep[p] + 1;
	f[x][0] = p; w[x][0] = weight;
	for(rgi i = 1; i <= lg2[dep[x]]; ++i)
	{
		f[x][i] = f[f[x][i - 1]][i - 1];
		w[x][i] = w[f[x][i - 1]][i - 1] + w[x][i - 1];
	}
	for(rgi i = first[x]; ~i; i = e[i]._next)
		if(e[i].to != p)	dfs(e[i].to, x, e[i].wt);
}

int lca(int u, int v)
{
	if(dep[u] > dep[v])	swap(u, v);
	int tmp = dep[v] - dep[u], ans = 0;
	for(rgi i = 0; i <= lg2[dep[v]]; ++i)
		if(tmp & (1 << i))
		{
			ans += w[v][i];
			v = f[v][i];
		}
	if(u == v)	return u;
	for(rgi i = lg2[dep[v]]; i >= 0; --i)
		if(f[u][i] != f[v][i])
		{
			ans += w[u][i] + w[v][i];
			u = f[u][i];
			v = f[v][i];
		}
	return ans + w[u][0] + w[v][0];
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n - 1; ++i)
	{
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);	
	}
	dfs(1, 0, oo);
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= n; ++j)
	return 0;
}

