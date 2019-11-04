#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 5e3 + 10;
const int M = 5e4 + 10;

int n, m, s, t, cnt, max_flow, min_cost;
int first[N], vis[N], dis[N], pre[N], last[N], flow[N];

struct edge
{
	int to, _next, wt, cap;
} e[M << 1];

struct QUEUE
{
	static const int MAX_SIZE = 2e5;
	int _head, _tail, que[MAX_SIZE + 10];
	void clear(){_head = _tail = 0;}
	void push(int val){que[++_tail] = val;}
	void pop(){(_head + 1 == _tail) ? (_head = _tail = 0) : (_head++);}
	int front(){return que[_head + 1];}
	int back(){return que[_tail];}
	int size(){return _tail - _head;}
	bool empty(){return _head == _tail;}
	QUEUE(){clear();}
} q;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int c, int w)
{
	e[cnt].to = v;
	e[cnt].cap = c;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

bool spfa(int S, int T)
{
	memset(vis, 0, sizeof(vis));
	memset(dis, oo, sizeof(dis));
	memset(flow, oo, sizeof(flow));
	q.push(S), dis[S] = 0, vis[S] = 1, pre[T] = -1;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		vis[x] = 0;
		for(rgi i = first[x]; ~i; i = e[i]._next)
		{
			int y = e[i].to;
			if(e[i].cap > 0 && dis[y] > dis[x] + e[i].wt)
			{
				dis[y] = dis[x] + e[i].wt;
				pre[y] = x;
				last[y] = i;
				flow[y] = min(flow[x], e[i].cap);
				if(!vis[y])
				{
					vis[y] = 1;
					q.push(y);
				}
			}
		}
	}
	return ~pre[T];
}

void MCMF()
{
	while(spfa(s, t))
	{
		max_flow += flow[t];
		min_cost += flow[t] * dis[t];
		for(rgi i = t; i != s; i = pre[i])
		{
			e[last[i]].cap -= flow[t];
			e[last[i] ^ 1].cap += flow[t];
		}
	}
}

int main()
{
	n = read(), m = read(), s = read(), t = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read(), c = read(), w = read();
		Add_Edge(u, v, c, w);
		Add_Edge(v, u, 0, -w);
	}
	MCMF();
	printf("%d %d", max_flow, min_cost);
	return 0;
}

