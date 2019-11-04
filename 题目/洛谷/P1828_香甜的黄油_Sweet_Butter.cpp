#include <cstdio>
#include <cstring>
#include <algorithm>
#define rgi register int
#define il inline
#define ll long long
#define maxn 800 + 10
#define maxm 1450 + 10
#define inf 0x3f3f3f3f

using namespace std;

int n, p, c, cnt, siz, minn = 0x3f3f3f3f;
int cow[maxn], first[maxn], vis[maxn], dis[maxn];

struct node
{
	int id, d;
} h[maxn];

struct edge
{
	int to, wt, _next;
} e[maxm << 1];

void push(int num, int val)
{
	h[++siz].id = num;
	h[siz].d = val;
	int cur = siz;
	while(cur >= 1)
	{
		if(h[cur].d < h[cur >> 1].d)
			swap(h[cur], h[cur >> 1]);
		else
			break;
		cur >>= 1;
	}
}

void pop()
{
	swap(h[1], h[siz]);
	h[siz].id = 0;
	h[siz--].d = 0;
	int cur = 1;
	while((cur << 1) <= siz)
	{
		int lc = cur << 1, rc = lc + 1, nxt;
		if(rc <= siz)
		{
			if(h[lc].d <= h[rc].d)
				nxt = lc;
			else
				nxt = rc;
		}
		else
			nxt = lc;
		if(h[nxt].d < h[cur].d)
		{
			swap(h[nxt], h[cur]);
			cur = nxt;
		}
		else
			break;
	}
}

struct node top()
{
	return h[1];
}

void Add_Edge(int u, int v, int w)
{
	e[++cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

void Dijkstra(int s)
{
	memset(vis, 0, sizeof(vis));
	memset(dis, inf, sizeof(dis));
	dis[s] = 0;
	push(s, 0);
	while(siz)
	{
		int x = top().id;
		pop();
		if(vis[x])
			continue;
		vis[x] = 1;
		for(rgi i = first[x]; i; i = e[i]._next)
		{
			int y = e[i].to;
			if(dis[y] > dis[x] + e[i].wt)
				dis[y] = dis[x] + e[i].wt;
			if(!vis[y])
				push(y, dis[y]);
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &p, &c);
	for(rgi i = 1; i <= n; ++i)
	{
		int t;
		scanf("%d", &t);
		cow[t]++;
	}
	for(rgi i = 1; i <= c; ++i)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);
	}
	for(rgi i = 1; i <= p; ++i)
	{
		int ans = 0;
		Dijkstra(i);
		for(rgi j = 1; j <= p; ++j)
			ans += cow[j] * dis[j];
		minn = min(ans, minn);
	}
	printf("%d", minn);
	return 0;
}
