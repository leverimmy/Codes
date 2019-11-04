#include <cstdio>
#include <cstring>
#include <queue>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 300 + 10;
const int M = 50000 + 10;
const int K = 30 + 10;

int n, m, _e, l, k, p, cnt, ans = oo;
int U[M], V[M], W[M], e[N][N];
int first[K * N], vis[K * N], dis[K * N];

struct edge
{
	int to, _next, wt;
} E[K * M];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int w)
{
	E[++cnt].to = v;
	E[cnt].wt = w;
	E[cnt]._next = first[u];
	first[u] = cnt;
}

void spfa(int s, int d0)
{
	memset(vis, 0, sizeof(vis));
	memset(dis, oo, sizeof(dis));
	queue <int> q;
	q.push(s);
	vis[s] = 1;
	dis[s] = d0;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		vis[x] = 0;
		for(rgi i = first[x]; i; i = E[i]._next)
		{
			int y = E[i].to;
			if(dis[y] > dis[x] + E[i].wt)
			{
				dis[y] = dis[x] + E[i].wt;
				if(!vis[y])
				{
					q.push(y);
					vis[y] = 1;
				}
			}
		}
	}
}

int main()
{
	n = read(), m = read(), _e = read(), p = read(), l = read(), k = read();
	memset(e, 0x3f, sizeof(e));
	for(rgi i = 1; i <= _e; ++i)
	{
		U[i] = read(), V[i] = read(), W[i] = read();
		e[U[i]][V[i]] = e[V[i]][U[i]] = min(e[U[i]][V[i]], W[i]);
	}
	for(rgi i = 1; i <= p; ++i)
	{
		int u = read(), v = read(), w = read();
		Add_Edge(v, u - 1, -w);
	}
	for(rgi i = 1; i <= n - 1; ++i)
	{
		Add_Edge(i, i + 1, 1);
		Add_Edge(i + 1, i, 0);
	}
	spfa(n, m);
	cnt = 0;
	memset(first, 0, sizeof(first));
	for(rgi i = 1; i <= _e; ++i)
		for(rgi j = 0; j <= k; j++)
		{
			Add_Edge(j * n + U[i], j * n + V[i], W[i]);
			Add_Edge(j * n + V[i], j * n + U[i], W[i]);
		}
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= n; ++j)
			for(rgi o = 1; o <= n; ++o)
				if(i != j && j != o && o != i && dis[o] - dis[o - 1] == 0 && dis[o] <= m)
					e[i][j] = min(e[i][j], e[i][o] + e[o][j]);
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= n; ++j)
			if(i != j && e[i][j] <= l)
				for(rgi o = 0; o <= k - 1; ++o)
					Add_Edge(o * n + i, (o + 1) * n + j, 0);
	spfa(1, 0);
	for(rgi i = 0; i <= k; ++i)
		ans = min(dis[i * n + n], ans);
	printf("%d", ans);
	return 0;
}

