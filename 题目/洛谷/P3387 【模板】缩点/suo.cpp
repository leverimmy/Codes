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

int n, m, ans;
int cnt, num, first[N], ideg[N], pri[N];
int idx, dfn[N], low[N];
int tot, belong[N], siz[N], instk[N];
int U[N], V[N], W[N], f[N];

struct edge
{
	int to, _next;
} e[M << 1];

struct STACK
{
	static const int MAX_SIZE = 2e5;
	int _top, stk[MAX_SIZE + 10];
	void clear(){_top = 0;}
	void push(int val){stk[++_top] = val;}
	void pop(){_top--;}
	int top(){return stk[_top];}
	int size(){return _top;}
	bool empty(){return _top == 0;}
	STACK(){clear();}
} stk;

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

il void Add_Edge(int u, int v)
{
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++idx;
	instk[u] = 1, stk.push(u);
	for(rgi i = first[u]; ~i; i = e[i]._next)
	{
		int v = e[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(instk[v])
			low[u] = min(low[u], dfn[v]);
	}
	if(dfn[u] == low[u])
	{
		tot++;
		while(stk.top() != u)
		{
			belong[stk.top()] = tot;
			siz[tot] += W[stk.top()];
			instk[stk.top()] = 0;
			stk.pop();
		}
		belong[u] = tot, siz[tot] += W[u];
		instk[u] = 0, stk.pop();
	}
}

void toposort()
{
	for(rgi i = 1; i <= tot; ++i)
		if(!ideg[i]) q.push(i), f[i] = siz[i]; 
	while(!q.empty())
	{
		int x = q.front(); q.pop(); pri[++num] = x;
		for(rgi i = first[x]; ~i; i = e[i]._next)
		{
			int y = e[i].to;
			ideg[y]--;
			if(!ideg[y])	q.push(y);
		}
	}
}

int main()
{
//	freopen("testdata (1).in", "r", stdin);
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i) W[i] = read();
	for(rgi i = 1; i <= m; ++i)
	{
		U[i] = read();
		V[i] = read();
		Add_Edge(U[i], V[i]);
	}
	for(rgi i = 1; i <= n; ++i)
		if(!dfn[i]) tarjan(i);
	memset(first, -1, sizeof(first)); cnt = 0;
	for(rgi i = 1; i <= m; ++i)
		if(belong[U[i]] != belong[V[i]])
		{
			Add_Edge(belong[U[i]], belong[V[i]]);
			ideg[belong[V[i]]]++;
		}
	toposort();
	for(rgi i = 1; i <= tot; ++i)
	{
		int x = pri[i];
		for(rgi j = first[x]; ~j; j = e[j]._next)
			f[e[j].to] = max(f[e[j].to], f[x] + siz[e[j].to]);
	}
	for(rgi i = 1; i <= tot; ++i)	ans = max(ans, f[i]);
	printf("%d", ans);
	return 0;
}
/*
10 20
970 369 910 889 470 106 658 659 916 964 
3 2
3 6
3 4
9 5
8 3
5 8
9 1
9 7
9 8
7 5
3 7
7 8
1 7
10 2
1 10
4 8
2 6
3 1
3 5
8 5

*/
