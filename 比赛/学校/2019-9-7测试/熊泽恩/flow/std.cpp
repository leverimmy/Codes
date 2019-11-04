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
const int N = 1e4 + 10;
const int M = 1e4 + 10;

int n, m, s, t, cnt, max_flow, flow;
int dep[N << 1], first[N << 1];

struct edge
{
	int to, _next, wt;
} e[M << 1];

struct QUEUE
{
	static const int MAX_SIZE = 4e5;
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
				if(y == t)
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
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i)
	{
		int ver_flow = read();
		Add_Edge(i, i + n, ver_flow);
		Add_Edge(i + n, i, 0);
	}
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read(), w = read();
		Add_Edge(u + n, v, w);
		Add_Edge(v, u + n, 0);
	}
	s = read(), t = read();
	while(bfs(s, t))
		while(flow = Dinic(s, oo))
			max_flow += flow;
	printf("%d", max_flow); 
	return 0;
}
/*
5 7
7 2 10 5 10
1 2 5
1 3 5
2 3 3
3 4 3
4 5 1
2 5 1
3 5 7
1 5

2 1
3 7
1 2 10
1 2

*/


