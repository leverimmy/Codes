#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <cstring>
#define il inline
#define rgi int
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, m, cnt, num, tot, sum;
int first[N], lg2[N] = {-1}, p[N], dep[N];
int f[N][50], w[N][50];

struct edge
{
	int to, _next, wt;
} e[M << 1];

struct EDGE
{
	int u, v, w;
} E[M << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void Add_Edge(int u, int v, int w)
{
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

int Find(int x){return x == p[x] ? x : p[x] = Find(p[x]);}
void Union(int a, int b){p[Find(a)] = Find(b);}
bool Check(int a, int b){return Find(a) == Find(b);}

bool cmp(struct EDGE a, struct EDGE b)
{
	return a.w < b.w;
}

void dfs(int x, int p, int weight)
{
	dep[x] = dep[p] + 1;
	f[x][0] = p; w[x][0] = weight;
	for(rgi i = 1; i <= lg2[dep[x]]; ++i)
	{
		f[x][i] = f[f[x][i - 1]][i - 1];
		w[x][i] = min(w[x][i], w[f[x][i - 1]][i - 1]);
	}
	for(rgi i = first[x]; ~i; i = e[i]._next)
		if(e[i].to != p)
			dfs(e[i].to, x, e[i].wt);
}

int lca(int u, int v)
{
	int ans = -oo;
	if(dep[u] > dep[v])
		swap(u, v);
	int tmp = dep[v] - dep[u];
	for(rgi i = 0; i <= lg2[dep[v]]; ++i)
		if(tmp & (1 << i))
		{
			ans = max(ans, w[v][i]);
			v = f[v][i];
		}
	if(u == v)
		return ans;
	for(rgi i = lg2[dep[v]]; i >= 0; --i)
		if(f[u][i] != f[v][i])
		{
			int ans1 = min(w[u][i], w[v][i]);
			ans = min(ans, ans1);
			u = f[u][0], v = f[v][0];
		}
	return max(ans, max(w[u][0], w[v][0]));
}

int main()
{
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	memset(w, oo, sizeof(w));
	for(rgi i = 1; i <= n; ++i)	lg2[i] = lg2[i >> 1] + 1;
	for(rgi i = 1; i <= n; ++i)	p[i] = i;
	for(rgi i = 1; i <= m; ++i)
	{
		E[i].u = read();
		E[i].v = read();
		E[i].w = read();
	}
	sort(E + 1, E + m + 1, cmp);
	for(rgi i = 1; i <= m; ++i)
	{
		if(!Check(E[i].u, E[i].v))
		{
			Union(E[i].u, E[i].v);
			tot++;
			sum += E[i].w;
			Add_Edge(E[i].u, E[i].v, E[i].w);
			Add_Edge(E[i].v, E[i].u, E[i].w);
		}
		if(tot == n - 1)	break;
	}
	dfs(1, 0, oo);
	for(rgi i = 2; i <= n; ++i)	num += lca(1, i);
	printf("%d", num);
	return 0;
	
}

