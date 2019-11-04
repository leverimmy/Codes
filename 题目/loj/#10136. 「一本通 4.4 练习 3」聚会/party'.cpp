#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define rgl register long long
#define il inline
#define ll long long

using namespace std;

const int N = 5e5 + 10;

int n, m, cnt;
int first[N], lg2[N] = { -1};
int f[N][50], dep[N];

struct edge
{
	int to, _next;
} e[N << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v)
{
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void dfs(int x, int p)
{
	dep[x] = dep[p] + 1;
	f[x][0] = p;
	for(rgi i = 1; i <= lg2[dep[x]]; ++i)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for(rgi i = first[x]; ~i; i = e[i]._next)
		if(e[i].to != p)
			dfs(e[i].to, x);
}

int lca(int u, int v)
{
	if(dep[u] > dep[v])
		swap(u, v);
	int tmp = dep[v] - dep[u];
	for(rgi i = 0; i <= lg2[dep[v]]; ++i)
		if(tmp & (1 << i))
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
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i)
		lg2[i] = lg2[i >> 1] + 1;
	for(rgi i = 1; i <= n - 1; ++i)
	{
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	dfs(1, 0);
	for(rgi i = 1; i <= m; ++i)
	{
		int a = read(), b = read(), c = read();
		int D = lca(a, b), E = lca(b, c), F = lca(a, c);
		printf("%d %d\n", D ^ E ^ F, dep[a] + dep[b] + dep[c] - dep[D] - dep[E] - dep[F]);
	}
	return 0;
}

