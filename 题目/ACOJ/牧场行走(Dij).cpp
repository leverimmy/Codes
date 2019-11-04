#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define rgi register int
#define il inline
#define ll long long
#define maxn 1010
#define inf 0x3f3f3f3f

using namespace std;

int n, m, cnt, siz;
int vis[maxn], first[maxn], dis[maxn];

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
	int id, val;
} h[maxn];

struct edge
{
	int to, _next, wt;
} e[maxn << 1];

il void Add_Edge(int u, int v, int w)
{
	e[++cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

il void push(int id, int val)
{
	h[++siz].val = val;
	h[siz].id = id;
	int cur = siz;
	while(cur > 1)
	{
		if(h[cur].val < h[cur >> 1].val)
			swap(h[cur], h[cur >> 1]);
		else
			break;
		cur >>= 1;
	}
}

il void pop()
{
	swap(h[1], h[siz--]);
	int cur = 1;
	while((cur << 1) <= siz)
	{
		int lc = cur << 1, rc = lc + 1, nxt;
		if(rc <= siz)
		{
			if(h[lc].val <= h[rc].val)
				nxt = lc;
			else
				nxt = rc;
		}
		else
			nxt = lc;
		if(h[cur].val > h[nxt].val)
			swap(h[cur], h[nxt]);
		else
			break;
		cur = nxt;
	}
}

struct node top()
{
	return h[1];
}

void dijkstra(int s)
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
	n = read(), m = read();
	for(rgi i = 1; i <= n - 1; ++i)
	{
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);
	}
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		dijkstra(u);
		write(dis[v]), putchar('\n');
	}
	return 0;
}
