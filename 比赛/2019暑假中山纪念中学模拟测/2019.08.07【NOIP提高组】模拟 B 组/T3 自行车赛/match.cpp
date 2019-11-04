#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 10000 + 10;
const int M = 20000 + 10;

int n, m, cnt, ans;
int first[N], vis[N], dis[N];

struct edge
{
	int to, _next, wt;
} e[M << 1];

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

void SPFA(int s)
{
	memset(vis, 0, sizeof(vis));
	memset(dis, -1, sizeof(dis));
	int q[N] = {0};
	int head = 1, tail = 2;
	q[head] = s;
	vis[s] = 1;
	dis[s] = 0;
	while(head < tail)
	{
		int x = q[head];
		head++;
		vis[x] = 0;
		for(rgi i = first[x]; i; i = e[i]._next)
		{
			int y = e[i].to;
			if(dis[y] < dis[x] + e[i].wt)
			{
				dis[y] = dis[x] + e[i].wt;
				if(!vis[y])
				{
					q[tail++] = y;
					vis[y] = 1;
				}
			}
		}
	}
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		Add_Edge(u, v, 1);
		Add_Edge(v, u, 1);
	}
	SPFA(1);
	for(rgi i = 1; i <= n; ++i)
		if(dis[i] != oo)
			ans = max(ans, dis[i]);
	printf("%d", ans);
	return 0;
}

