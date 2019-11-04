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
#define maxn 15010<<1
#define maxm 30010<<1

using namespace std;

int n, m, k, cnt;
int first[maxn], p[maxn], vis[maxn], dep[maxn];
int f[maxn][50], w[maxn][50];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)    putchar('-'), x = -x;
	if(x > 9)    write(x / 10);
	putchar(x % 10 + 48);
}

struct node
{
	int u, v, w;
} e[maxm];

bool cmp1(struct node a, struct node b)
{
	return a.w < b.w;
}

struct edge
{
	int to, _next, wt;
} E[maxn];

void Add_Edge(int u, int v, int w)
{
	E[++cnt].to = v;
	E[cnt].wt = w;
	E[cnt]._next = first[u];
	first[u] = cnt;
}

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

int _union(int a, int b)
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

void dfs(int x)
{
	vis[x] = 1;
	for(rgi i = first[x]; i; i = E[i]._next)
	{
		int y = E[i].to;
		if(vis[y])
			continue;
		dep[y] = dep[x] + 1;
		f[y][0] = x;
		w[y][0] = E[i].wt;
		dfs(y);
	}
}

int lca(int u, int v)
{
	if(find(u) != find(v))
		return -1;
	int res = -1;
	if(dep[u] > dep[v])
		swap(u, v);
	for(rgi i = 20; i >= 0; i--)
		if(dep[f[v][i]] >= dep[u])
		{
			res = max(res, w[v][i]);
			v = f[v][i];
		}
	if(u == v)
		return res;
	for(rgi i = 20; i >= 0; i--)
		if(f[u][i] != f[v][i])
		{
			res = max(res, max(w[u][i], w[v][i]));
			u = f[u][i];
			v = f[v][i];
		}
	res = max(res, max(w[u][0], w[v][0]));
	return res;
}

int main()
{
	n = read(), m = read(), k = read();
	for(rgi i = 1; i <= n; ++i)
		p[i] = i;
	for(rgi i = 1; i <= m; ++i)
	{
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
	}
	sort(e + 1, e + m + 1, cmp1);
	for(rgi i = 1; i <= m; ++i)
	{
		if(cnt == n - 1)
			break;
		if(_union(e[i].u, e[i].v))
		{
			Add_Edge(e[i].u, e[i].v, e[i].w);
			Add_Edge(e[i].v, e[i].u, e[i].w);
		}
	}
	for(rgi i = 1; i <= n; ++i)
		if(!vis[i])
		{
			dep[i] = 1;
			dfs(i);
			f[i][0] = i;
			w[i][0] = -1;
		}
	for(rgi i = 1; i <= 20; ++i)
		for(rgi j = 1; j <= n; ++j)
		{
			f[j][i] = f[f[j][i - 1]][i - 1];
			w[j][i] = max(w[j][i - 1], w[f[j][i - 1]][i - 1]);
		}
	for(rgi i = 1; i <= k; ++i)
	{
		int u = read(), v = read();
		write(lca(u, v)), putchar('\n');
	}
	return 0;
}

