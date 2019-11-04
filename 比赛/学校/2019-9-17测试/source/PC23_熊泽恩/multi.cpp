#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <algorithm>
#define il inline
#define rgi register int
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 5e4 + 10;
const int M = 1e5 + 10;

int n, m, cnt, ans, u, s, t, siz;
int vis[N], first[N], pre[N];
double dis[N];

stack <int> stk;

struct edge
{
	int to, _next, wt;
} e[M << 1];

struct node
{
	int id;
	double val;
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
	e[cnt].wt = w;
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void push(int id, double val)
{
	h[++siz].id = id;
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
			if(h[lc].val < h[rc].val)
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

void Dijkstra()
{
	memset(vis, 0, sizeof(vis));
	for(rgi i = 1; i <= n; ++i)	dis[i] = oo;
	dis[s] = 0, push(s, 0);
	while(siz)
	{
		struct node cur = top(); pop();
		int x = cur.id;
		if(vis[x]) continue;
		vis[x] = 1;
		for(rgi i = first[x]; ~i; i = e[i]._next)
		{
			int y = e[i].to;
			if(dis[y] > dis[x] + log(e[i].wt))
			{
				dis[y] = dis[x] + log(e[i].wt);
				pre[y] = x;
				if(!vis[y])
					push(y, dis[y]);
			}
		}
	}
}

int main()
{
	freopen("multi.in", "r", stdin);
	freopen("multi.out", "w", stdout);
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	memset(pre, -1, sizeof(pre));
	for(rgi i = 1; i <= m; i++)
	{
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);
	}
	s = read(), t = read();
	Dijkstra(); u = t;
//	while(~pre[u])
//	{
//		printf("%d ", u);
//		u = pre[u];
//	} printf("%d", s);
	while(~pre[u])
	{
		stk.push(u);
		u = pre[u];
	} stk.push(s);
	while(!stk.empty())
	{
		printf("%d ", stk.top());
		stk.pop();
	}
	return 0;
}
/*
4 4
1 2 3
2 4 2
4 3 2
1 3 15
1 3

*/
