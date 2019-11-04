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
const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, m, s, t, cnt, max_flow, flow;
int dep[N], first[N];

struct edge
{
	int to, _next, wt;
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
};

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

bool bfs(int S, int T)
{
	memset(dep, 0, sizeof(dep));
	struct QUEUE q;
	q.push(S), dep[S] = 1;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for(rgi i = first[x]; ~i; i = e[i]._next)
		{
			int y = e[i].to;
			if(e[i].wt && !dep[y])
			{
				dep[y] = dep[x] + 1;
				q.push(y);
				if(y == T)
					return 1;
			}
		}
	}
	return 0;
}

int Dinic(int x, int FLOW)
{
	if(x == t)
		return FLOW;
	int rest = FLOW;
	for(rgi i = first[x]; ~i; i = e[i]._next)
	{
		int y = e[i].to;
		if(e[i].wt && dep[y] == dep[x] + 1)
		{
			int cur_flow = Dinic(y, min(rest, e[i].wt));
			if(!cur_flow)
				dep[y] = 0;
			e[i].wt -= cur_flow;
			e[i ^ 1].wt += cur_flow;
			rest -= cur_flow;
		}
	}
	return FLOW - rest;
}

int main()
{
	n = read(), m = read(), s = read(), t = read();
//	n = read(), m = read(), s = 1, t = m;
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, 0); 
	}
	while(bfs(s, t))
		while(flow = Dinic(s, oo))
			max_flow += flow;
	printf("%d", max_flow);
	return 0;
}

