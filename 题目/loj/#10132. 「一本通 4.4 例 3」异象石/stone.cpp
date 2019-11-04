#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <set>
#define ll long long
#define il inline
#define rgi register int
#define rgl register long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;

int n, m, cnt, idx;
int first[N], dep[N], lg2[N] = { -1}, dis[N];
int dfn[N];
int f[N][50];

struct node
{
	int id, dfn;
}

set <struct node> s;

struct edge
{
	int to, _next, wt;
} e[N << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int w)
{
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void dfs(int x, int p, int weight)
{
	p[x].id = x;
	p[x].dfn = ++idx;
	s.push(p[x]);
	dep[x] = dep[p] + 1;
	dis[x] = dis[p] + weight;
	f[x][0] = p;
	for(rgi i = 1; i <= lg2[dep[x]]; ++i)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for(rgi i = first[x]; ~i; i = e[i]._next)
		if(e[i].to != p)
			dfs(e[i].to, x, e[i].wt);
}

int lca(int u, int v)
{
	if(dep[u] > dep[v])
		swap(u, v);
	int temp = dep[v] - dep[u];
	for(rgi i = 0; i <= lg2[dep[v]]; ++i)
		if(temp & (1 << i))
			v = f[v][i];
	for(rgi i = lg2[dep[v]]; i >= 0; --i)
		if(f[u][i] != f[v][i])
		{
			u = f[u][i];
			v = f[v][i];
		}
	return f[u][0];
}

bool operator < (struct node a, struct node b)
{
	return a.dfn < b.dfn;
}

int main()
{
	n = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i)
		lg2[i] = lg2[i >> 1] + 1;
	for(rgi i = 1; i <= n - 1; ++i)
	{
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);
	}
	dfs(1, 0, oo);
	for(rgi i = 1; i <= m; ++i)
	{
		scanf("%s", op);
		if(op[0] == '+')
		{
			int x = read();
			s.insert(p[x]);
		}
		else if(op[0] == '-')
		{
			int x = read();
			s.erase(p[x]);
		}
		else if(op[0] == '?')
			printf("%d\n", ans);
	}
	return 0;
}
