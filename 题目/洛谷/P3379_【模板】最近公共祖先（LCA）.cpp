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
#define inf 0x3f3f3f3f

using namespace std;

int n, m, s, cnt;
int first[maxn], depth[maxn], lg2[maxn];
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
	int to, _next;
} e[maxm << 1];

void Add_Edge(int u, int v)
{
	e[++cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

void dfs(int x, int p)
{
	depth[x] = depth[p] + 1;
	f[x][0] = p;
	for(rgi i = 1; (1 << i) <= depth[x]; ++i)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for(int i = first[x]; i; i = e[i]._next)
		if(e[i].to != p)
			dfs(e[i].to, x);
}

void lg()
{
	for(rgi i = 1; i < maxn; ++i)
		lg2[i] = lg2[i >> 1] + 1;
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
	n = read(), m = read(), s = read();
	lg();
	for(rgi i = 1; i <= n - 1; ++i)
	{
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	dfs(s, 0);
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		write(lca(u, v)), putchar('\n');
	}
	return 0;
}

