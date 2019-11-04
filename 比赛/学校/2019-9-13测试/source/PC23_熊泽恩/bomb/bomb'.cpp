#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 5000 + 10;
const int M = 1e5 + 10;

int n, m, cnt, siz;
int first[N], V[N], k[N];

struct edge
{
	int to, _next;
	ll wt;
} e[M << 1];

struct node
{
	int id, val;
} h[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int w)
{
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void push(int id, int val)
{
	siz++;
	h[siz].id = id;
	h[siz].val = val;
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

void pop()
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
		if(h[nxt].val < h[cur].val)
			swap(h[nxt], h[cur]);
		else
			break;
		cur = nxt;
	}
}

struct node top()
{
	return h[1];
}

void Dijkstra(int s)
{
	memset(dis, oo, sizeof(dis));
	memset(vis, 0, sizeof(vis);
	push(s, 0), dis[s] = 0;
	while(siz)
	{
		int x = top().id;
		pop();
		if(vis[x])	continue;
		vis[x] = 1;
		for(rgi i = first[x]; ~i; i = e[i]._next)
		{
			int y = e[i].to;
			if(dis[y] > dis[x] + e[i].wt)
			{
				dis[y] = dis[x] + e[i].wt;
				if(!vis[y])
				{
					vis[y] = 1;
					push(y, dis[y]);
				}
			}
		}
	}
}

int main()
{
//	freopen("bomb.in", "r", stdin);
//	freopen("bomb.out", "w", stdout);
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);
	}
	for(rgi i = 1; i <= n - 2; ++i)
	{
		k[i + 1] = read();
		for(rgi j = 1; j <= k[i + 1]; ++j)
		{
			int cur = read();
			V[cur]++;
		}
	}
	
	return 0;
}

