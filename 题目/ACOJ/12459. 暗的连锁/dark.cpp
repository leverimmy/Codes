#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int
#define maxn 100010

using namespace std;

int n, m, cnt, ans;
int lg2[maxn] = { -1}, first[maxn];
int dep[maxn], val[maxn];
int f[maxn][50];

struct edge
{
	int to, _next;
} e[maxn << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void init()
{
	for(rgi i = 1; i <= n; ++i)
		lg2[i] = lg2[i >> 1] + 1;
}

void Add_Edge(int u, int v)
{
	e[++cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

void dfs1(int x, int p)
{
	dep[x] = dep[p] + 1;
	f[x][0] = p;
	for(rgi i = 1; i <= lg2[dep[x]]; ++i)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for(rgi i = first[x]; i; i = e[i]._next)
		if(e[i].to != p)
			dfs1(e[i].to, x);
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

void dfs2(int x, int p)
{
	for(rgi i = first[x]; i; i = e[i]._next)
		if(e[i].to != p)
		{
			dfs2(e[i].to, x);
			val[x] += val[e[i].to];
		}
	if(x == 1)
		return;
	if(val[x] == 0)
		ans += m;
	else if(val[x] == 1)
		ans++;
}

int main()
{
	n = read(), m = read();
	init();
	for(rgi i = 1; i <= n - 1; ++i)
	{
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	dfs1(1, 0);
	for(rgi i = 1; i <= m; ++i)
	{
		int s = read(), t = read();
		val[s]++;
		val[t]++;
		val[lca(s, t)] -= 2;
	}
	dfs2(1, 0);
	printf("%d", ans);
	return 0;
}

