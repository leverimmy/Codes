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

int n, m, k, cnt, siz, tot;
int first[maxn], p[maxn << 2], f[maxn][50], val[maxn], lg2[maxn] = { -1, 0}, dep[maxn];

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

bool cmp(struct node a, struct node b)
{
	return a.w < b.w;
}

struct edge
{
	int to, _next;
} E[maxm];

void Add_Edge(int u, int v)
{
	E[++tot].to = v;
	E[tot]._next = first[u];
	first[u] = tot;
}

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

int _union(int i)
{
	int a = e[i].u;
	int b = e[i].v;
	int pa = find(a);
	int pb = find(b);
	if(pa != pb)
	{
		p[pa] = p[pb] = ++siz;
		Add_Edge(pa, siz), Add_Edge(siz, pa);
		Add_Edge(pb, siz), Add_Edge(siz, pb);
		val[siz] = e[i].w;
		return 1;
	}
	return 0;
}

void lg()
{
	for(rgi i = 1; i < maxn; ++i)
		lg2[i] = lg2[i >> 1] + 1;
}

void dfs(int x, int _p)
{
	dep[x] = dep[_p] + 1;
	f[x][0] = _p;
	for(rgi i = 1; (1 << i) <= dep[x]; ++i)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for(rgi i = first[x]; i; i = E[i]._next)
		if(E[i].to != _p)
			dfs(E[i].to, x);
}

int lca(int u, int v)
{
	if(dep[u] < dep[v])
		swap(u, v);
	while(dep[u] > dep[v])
		u = f[u][lg2[dep[u] - dep[v]] - 1];
	if(u == v)
		return u;
	for(rgi i = lg2[dep[u]] - 1; i >= 0; i--)
		if(f[u][i] != f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}

int main()
{
	n = read(), m = read(), k = read();
	lg(), siz = n;
	for(rgi i = 1; i < maxn; ++i)
		p[i] = i;
	for(rgi i = 1; i <= m; ++i)
	{
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
	}
	sort(e + 1, e + m + 1, cmp);
	for(rgi i = 1; i <= m; ++i)
	{
		if(cnt == n - 1)
			break;
		if(_union(i))
			cnt++;
	}
	dfs(1, 0);
	for(rgi i = 1; i <= k; ++i)
	{
		int x = read(), y = read();
		write(val[lca(x, y)]), putchar('\n');
	}
	return 0;
}

