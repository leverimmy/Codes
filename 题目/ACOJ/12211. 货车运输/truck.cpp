#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int
#define maxn 10010
#define maxm 50010

using namespace std;

const int oo = 0x3f3f3f3f;

int n, m, q, cnt, CNT;
int p[maxn];
int first[maxn], dep[maxn], lg2[maxn] = { -1}, vis[maxn];
int f[maxn][50], w[maxn][50];

struct edge
{
	int to, _next, wt;
} e[maxm << 1];

struct EDGE
{
	int u, v, w;
} E[maxm << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct EDGE a, struct EDGE b)
{
	return a.w > b.w;
}

void Add_Edge(int u, int v, int w)
{
	e[++cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

void init()
{
	for(rgi i = 1; i <= n; ++i)
	{
		lg2[i] = lg2[i >> 1] + 1;
		p[i] = i;
	}
}

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

int uunion(int a, int b)
{
	int pa = find(a);
	int pb = find(b);
	if(pa != pb)
	{
		p[pa] = pb;
		return 1;
	}
	return 0;
}

void dfs(int x, int p, int weight)
{
	vis[x] = 1;
	dep[x] = dep[p] + 1;
	f[x][0] = p;
	w[x][0] = weight;
	for(rgi i = 1; i <= lg2[dep[x]]; ++i)
	{
		f[x][i] = f[f[x][i - 1]][i - 1];
		w[x][i] = min(w[x][i - 1], w[f[x][i - 1]][i - 1]);
	}
	for(rgi i = first[x]; i; i = e[i]._next)
		if(!vis[e[i].to])
			dfs(e[i].to, x, e[i].wt);
}

int lca(int u, int v)
{
	int ans = oo;
	if(dep[u] > dep[v])
		swap(u, v);
	int temp = dep[v] - dep[u];
	for(rgi i = 0; i <= lg2[dep[v]]; ++i)
		if(temp & (1 << i))
		{
			ans = min(ans, w[v][i]);
			v = f[v][i];
		}
	if(u == v)
		return ans;
	for(rgi i = lg2[dep[v]]; i >= 0; --i)
		if(f[u][i] != f[v][i])
		{
			ans = min(ans, w[u][i]);
			ans = min(ans, w[v][i]);
			u = f[u][i];
			v = f[v][i];
		}
	return min(ans, min(w[u][0], w[v][0]));
}

int main()
{
	n = read(), m = read();
	init();
	for(rgi i = 1; i <= m; ++i)
	{
		E[i].u = read();
		E[i].v = read();
		E[i].w = read();
	}
	sort(E + 1, E + m + 1, cmp);
	for(rgi i = 1; i <= m; ++i)
	{
		if(CNT == n - 1)
			break;
		if(uunion(E[i].u, E[i].v))
		{
			Add_Edge(E[i].u, E[i].v, E[i].w);
			Add_Edge(E[i].v, E[i].u, E[i].w);
		}
	}
	dfs(1, 0, oo);
	q = read();
	for(rgi i = 1; i <= q; ++i)
	{
		int s = read(), t = read();
		if(find(s) != find(t))
			puts("-1");
		else
			printf("%d\n", lca(s, t));
	}
	return 0;
}

