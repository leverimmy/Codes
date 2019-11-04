#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 50 + 10;
const int M = 4000 + 10;

int n, m, k, cnt, siz, ans = oo;
int first[N], vis[N], dis[N], pre[N], done[N];

struct edge
{
	int to, _next;
} e[M << 1];

struct node
{
	int id, val;
} h[N];

il int read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v)
{
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void push(int num, int val)
{
	h[++siz].id = num;
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

bool Dijkstra(int s)
{
	memset(vis, 0, sizeof(vis));
	memset(dis, oo, sizeof(dis));
	dis[s] = 0;
	push(s, 0);
	while(siz)
	{
		int x = top().id;
		pop();
		if(vis[x])
			continue;
		vis[x] = 1;
		for(rgi i = first[x]; ~i; i = e[i]._next)
		{
			int y = e[i].to;
			if((!done[y]) && dis[y] > dis[x] + 1)
			{
				dis[y] = dis[x] + 1;
				pre[y] = x;
				if(!vis[y])
					push(y, dis[y]);
			}
		}
	}
	return dis[n] > k;
}

void dfs(int cur)
{
	if(cur >= ans)
		return;
	while(Dijkstra(1))
	{
		ans = cur;
		return;
	}
	int x = pre[n];
	while(x != 1)
	{
		done[x] = 1;
		dfs(cur + 1);
		done[x] = 0;
		x = pre[x];
	}
}

int main()
{
//	freopen("bus.in", "r", stdin);
//	freopen("bus.out", "w", stdout);
	n = read(), m = read(), k = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		Add_Edge(u, v);
	}
	dfs(0);
	printf("%d", ans);
	return 0;
}

