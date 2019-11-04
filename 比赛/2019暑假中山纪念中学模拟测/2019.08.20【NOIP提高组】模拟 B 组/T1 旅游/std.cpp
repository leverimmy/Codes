#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <string>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const int NODES = 1000 + 10;
const int EDGES = 1000 + 10;
const int N = NODES * EDGES;
const int M = NODES * EDGES;

int n, m, s = 1, tot1, tot2, tot3, cnt;
int s_val, t_val;
int first[N], vis[N], to[N];
int A[NODES][NODES], B[NODES][NODES];
ll ans = -oo, dis[N];

vector <int> vec[N];

struct Point
{
	int x, y;
	ll a, b;
} p[M << 1], tmp[M << 1];

bool cmp_Point(struct Point X, struct Point Y)
{
	return X.a < Y.a;
}

struct Edge
{
	int to, _next;
	ll wt;
} e[2000100];

il int read()
{
	rgi f = 0, x = 0, ch;
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

ll dist(int a, int b)
{
	return abs(p[a].x - p[b].x) + abs(p[a].y - p[b].y);
}

void SPFA(int s)
{
	memset(vis, 0, sizeof(vis));
	memset(dis, 0, sizeof(dis));
	queue <int> q;
	q.push(s);
	vis[s] = 1;
	dis[s] = p[s].b;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		vis[x] = 0;
		for(rgi i = first[x]; ~i; i = e[i]._next)
		{
			int y = e[i].to;
			if(dis[y] < dis[x] + e[i].wt)
			{
				dis[y] = dis[x] + e[i].wt;
				if(!vis[y])
				{
					q.push(y);
					vis[y] = 1;
				}
			}
		}
	}
}

void UNIQUE()
{
	for(rgi i = 1; i <= tot2; ++i)
	{
		if(!to[p[i].a])
			to[p[i].a] = ++tot3;
		vec[tot3].push_back(i);
	}
	for(rgi i = 1; i <= tot2; ++i)
	{
		int cur = to[p[i].a] + 1;
		for(rgi j = 0; j < vec[cur].size(); ++j)
			Add_Edge(i, vec[cur][j], dist(i, vec[cur][j]) + p[vec[cur][j]].b);
	}
}

int main()
{
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j)
			A[i][j] = read();
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j)
			B[i][j] = read();
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j)
		{
			tot1++;
			tmp[tot1].x = i;
			tmp[tot1].y = j;
			tmp[tot1].a = A[i][j];
			tmp[tot1].b = B[i][j];
		}
	sort(tmp + 1, tmp + tot1 + 1, cmp_Point);
	for(rgi i = 1; i <= tot1; ++i)
	{
		if(tmp[i].a || tmp[i].b)
		{
			tot2++;
			p[tot2].x = tmp[i].x;
			p[tot2].y = tmp[i].y;
			p[tot2].a = tmp[i].a;
			p[tot2].b = tmp[i].b;
		}
	}
	UNIQUE();
	s_val = p[1].a;
	t_val = p[tot2].a;
	while(p[s].a == s_val)
	{
		SPFA(s);
		s++;
		int t = tot2;
		while(p[t].a == t_val)
		{
			ans = max(ans, dis[t]);
			t--;
		}
	}
	printf("%lld", ans);
	return 0;
}

