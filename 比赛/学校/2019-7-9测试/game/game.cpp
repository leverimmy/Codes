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
#define maxn 30010
#define maxm 30010

using namespace std;

int n, m, s, cnt, last, cur, ans;
int first[maxn], dep[maxn], lg2[maxn] = { -1, 0};
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
		if((1 << i) & temp)
			v = f[v][i];
	if(u == v)
		return u;
	for(rgi i = lg2[dep[u]]; i >= 0; i--)
		if(f[u][i] != f[v][i])
		{
			u = f[u][i];
			v = f[v][i];
		}
	return f[u][0];
}

int dis(int u, int v)
{
	return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int main()
{
//	freopen("game10.in", "r", stdin);
//	freopen("ggggg.out", "w", stdout);
	n = read();
	for(rgi i = 1; i < maxn; ++i)
		lg2[i] = lg2[i >> 1] + 1;
	for(rgi i = 1; i <= n - 1; ++i)
	{
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
		s = u;
	}
	m = read();
	dfs(s, 0);
	for(rgi i = 1; i <= m; ++i)
	{
		if(i == 1)
			last = read();
		else
		{
			cur = read();
			ans += dis(last, cur);
			last = cur;
		}
	}
	printf("%d", ans);
	return 0;
}

