#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <queue>
#define il inline
#define rgi register int
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int M = 1e5 + 10;

int T, n, m, cnt;
int first[N], vis[N], dis[N], f[N];

queue <int> q;

struct edge
{
	int to, _next, wt;
} e[M << 1];

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

bool spfa()
{
	memset(vis, 0, sizeof(vis));
	memset(dis, oo, sizeof(dis));
	dis[0] = 0; vis[0] = 1; q.push(0); 
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		vis[x] = 0;
		for(rgi i = first[x]; ~i; i = e[i]._next)
		{
			int y = e[i].to;
			if(dis[y] > dis[x] ^ e[i].wt)
			{
				dis[y] = dis[x] ^ e[i].wt;
				if(!vis[y])
				{
					vis[y] = 1;
					q.push(y);
					f[y]++;
				}
			}
		}
		if(f[x] >= n)	return 0;
	}
	return 1; 
}

int main()
{
//	freopen("xor.in", "r", stdin);
//	freopen("xor.out", "w", stdout);
	T = read();
	while(T--)
	{
		n = m = cnt = 0;
		n = read(), m = read();
		memset(first, -1, sizeof(first));
		memset(f, 0, sizeof(f));
		for(rgi i = 1; i <= m; ++i)
		{
			int u = read(), v = read(), w = read();
			Add_Edge(v, u - 1, -w);
			Add_Edge(u - 1, v, w);
		}
		for(rgi i = 1; i <= n; ++i) Add_Edge(0, i, 0);
		if(spfa())	puts("YES");
		else		puts("NO");
	}
	return 0;
}

