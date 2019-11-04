#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <vector>
#include <cstring>
#include <queue>
#define rgi register int
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 5000 + 10;
const int M = 1e5 + 10;

int n, m, cnt, ans = -oo, siz, flag;
int first[N], vis[N], dis[N], V[N];

vector <int> protect[N];

struct edge
{
	int to, _next;
	int wt;
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

bool operator < (struct node a, struct node b)
{
	return a.val < b.val;
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
		if(h[cur] < h[cur >> 1])
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
			if(h[lc] < h[rc])
				nxt = lc;
			else
				nxt = rc;
		}
		else
			nxt = lc;
		if(h[nxt] < h[cur])
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

void Dijkstra()
{
	memset(dis, oo, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	push(1, 0), dis[1] = 0;
	while(siz)
	{
		int x = top().id;
		pop();
		if(vis[x])	continue;
		vis[x] = 1;
		for(rgi i = 0; i < protect[x].size(); ++i)
		{
			int y = protect[x][i];
			V[y]--;
			dis[y] = max(dis[y], dis[x]);
			if(V[y] == 0)
				push(y, dis[y]);
		}
		protect[x].clear();
		
		for(rgi i = first[x]; ~i; i = e[i]._next)
		{
			int y = e[i].to;
			if(dis[y] > dis[x] + e[i].wt)
			{
				dis[y] = dis[x] + e[i].wt;
				if(!V[y])
					push(y, dis[y]);
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
	for(rgi i = 2; i <= n - 1; ++i)
	{
		int tot = read();
		for(rgi j = 1; j <= tot; ++j)
		{
			int cur = read();
			protect[i].push_back(cur);
			V[cur]++;
		}
	}
	Dijkstra();
	if(dis[n] == oo)
		puts("Mission Failed");
	else
		printf("%d", dis[n]);
	return 0;
}
/*
6 6
1 2 1
1 4 3
2 3 1
2 5 2
4 6 2
5 3 2
0
1 6
0
2 4 6

*/

