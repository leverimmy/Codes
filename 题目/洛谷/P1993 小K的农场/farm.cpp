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
#define maxn 10010 << 1
#define maxm 10010 << 2

using namespace std;

const int inf = 0x3f3f3f3f;

int n, m, cnt;
int first[maxn], vis[maxn], dis[maxn];

struct edge
{
	int to, _next, wt;
} e[maxm];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int w)
{
	e[++cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

bool spfa(int s)
{
	vis[s] = 1;
	for(rgi i = first[s]; i; i = e[i]._next)
	{
		int t = e[i].to;
		if(dis[t] < dis[s] + e[i].wt)
		{
			dis[t] = dis[s] + e[i].wt;
			if(vis[t])
				return 0;
			if(!spfa(t))
				return 0;
		}
	}
	vis[s] = 0;
	return 1;
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
		dis[i] = -inf;
	for(rgi i = 1; i <= m; ++i)
	{
		int op = read();
		if(op == 1)
		{
			int u = read(), v = read(), w = read();
			Add_Edge(v, u, w);
		}
		else if(op == 2)
		{
			int u = read(), v = read(), w = read();
			Add_Edge(u, v, -w);
		}
		else if(op == 3)
		{
			int u = read(), v = read();
			Add_Edge(u, v, 0);
			Add_Edge(v, u, 0);
		}
	}
	for(rgi i = 1; i <= n; ++i)
		Add_Edge(0, i, 0);
	if(spfa(0))
		puts("Yes");
	else
		puts("No");
	return 0;
}

