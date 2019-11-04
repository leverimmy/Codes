#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <queue>
#define ll long long
#define il inline
#define rgi register int
#define rgl register ll

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 30000 + 10;
const int M = 100000 + 10;

int n, m, cnt, minn = oo;;
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
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void SPFA(int s)
{
	memset(vis, 0, sizeof(vis));
	memset(dis, oo, sizeof(dis));
	queue <int> q;
	q.push(s);
	vis[s] = 1, dis[s] = 0;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		vis[x] = 0;
		for(rgi i = first[x]; ~i; i = e[i]._next)
		{
			int y = e[i].to;
			if(dis[y] > dis[x] + e[i].wt)
			{
				dis[y] = dis[x] + e[i].wt;
				if(!vis[y])
				{
					vis[y] = 1;
					q.push(y);
				}
			}
		}
	}
}

int main()
{
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read(), w = read();
		Add_Edge(v, u - 1, -w);
		//s[v] - s[u - 1] >= w
	}
	for(rgi i = 0; i <= n; ++i)
	{
		Add_Edge(n + 1, i, 0);
		//s[n + 1] - s[i] >= 0
	}
	for(rgi i = 1; i <= n; ++i)
	{
		Add_Edge(i - 1, i, 1);
		//s[i - 1] - s[i] >= 1
		Add_Edge(i, i - 1, 0);
		//s[i] - s[i - 1] >= 0
	}
	SPFA(n + 1);
	for(rgi i = 0; i <= n; ++i)
		minn = min(minn, dis[i]);//找到最小的前缀和a
	printf("%d", dis[n] - minn);
	return 0;
}

