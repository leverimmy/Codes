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
const int N = 2e3 + 10;
const int M = 5e6 + 10;

int n, m, k, rt, ans = oo;
int cnt, first[N], dep[N];
int hole[N], vis[N], dis[N];

struct edge
{
	int to, _next;
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

il void Add_Edge(int u, int v)
{
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void bfs()
{
	struct QUEUE q;
	q.push(rt), dep[rt] = 0;
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		if(vis[x])	continue;
		vis[x] = 1;
		for(rgi i = first[x]; ~i; i = e[i]._next)
		{
			int y = e[i].to;
			dep[y] = dep[x] + 1;
			q.push(y);
		}
	}
}

int dfs(int x)
{
	
}

int main()
{
//	freopen("holes.in", "r", stdin);
//	freopen("holes.out", "w", stdout);
	n = read(), m = read(), k = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		deg[u]++, deg[v]++; 
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	for(rgi i = 1; i <= n; ++i)	if(deg[i] > 3)	rt = i;
	if(!rt)	printf("%d", (n - t - 1) / (2 * t) + 1);
	else if(n == k) puts("0");
	else
	{
		l = 1, r = n;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(Check(mid))
				l = mid + 1;
			else
				r = mid;
			ans = mid;
		}
		printf("%d", ans);
	}
	return 0;
}
/*
5 5 2
1 2
2 3
3 1
1 4
4 5

*/
