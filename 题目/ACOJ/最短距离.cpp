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
#define maxn 10010
#define maxm 10010

using namespace std;

int n, m, cnt;
int first[maxn], depth[maxn], dis[maxn], lg2[maxn];
int f[maxn][50];

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
	int to, _next, wt;
} e[maxm << 1];

void Add_Edge(int u, int v, int w)
{
	e[++cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

void lg()
{
	for(rgi i = 1; i < maxn; ++i)
		lg2[i] = lg2[i >> 1] + 1;
}

void dfs(int x, int p)
{
	depth[x] = depth[p] + 1;
	f[x][0] = p;
	for(rgi i = 1; (1 << i) <= depth[x]; ++i)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for(rgi i = first[x]; i; i = e[i]._next)
	{
		int y = e[i].to;
		if(y != p)
		{
			dis[y] = dis[x] + e[i].wt;
			dfs(y, x);
		}
	}
}

int lca(int u, int v)
{
	if(depth[u] < depth[v])
		swap(u, v);
	while(depth[u] > depth[v])
		u = f[u][lg2[depth[u] - depth[v]] - 1];
	if(u == v)
		return u;
	for(rgi i = lg2[depth[u]] - 1; i >= 0; i--)
		if(f[u][i] != f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}

int main()
{
	lg();
	n = read(), m = read();
	for(rgi i = 1; i <= n - 1; ++i)
	{
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);
	}
	dfs(1, 0);
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		write(dis[u] + dis[v] - 2 * dis[lca(u, v)]), putchar('\n');
	}
	return 0;
}

