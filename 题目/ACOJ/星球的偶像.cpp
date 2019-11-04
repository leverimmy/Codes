#include <cstdio>
#include <algorithm>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long
#define maxn 10010
#define maxm 50010

using namespace std;

int n, m, siz, cnt, _index, color, tot, cur;
int _stack[maxn], vis[maxn];
int low[maxn], dfn[maxn];
int _in[maxn], _out[maxn], p[maxn], cnt_size[maxn];
int first[maxn], new_first[maxn];

il void push(int val)
{
	_stack[++siz] = val;
}

il void pop()
{
	_stack[siz--] = 0;
}

il int top()
{
	return _stack[siz];
}

struct edge
{
	int to, _next;
} e[maxm], new_e[maxm];

il void Add_Edge(int u, int v)
{
	e[++cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

il void new_Add_Edge(int u, int v)
{
	new_e[++cnt].to = v;
	new_e[cnt]._next = new_first[u];
	new_first[u] = cnt;
}

il void Tarjan(int u)
{
	int v;
	dfn[u] = low[u] = ++_index;
	push(u), vis[u] = 1;
	for(rgi i = first[u]; i; i = e[i]._next)
	{
		v = e[i].to;
		if(!dfn[v])
		{
			Tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(vis[v])
			low[u] = min(low[u], dfn[v]);
	}
	if(dfn[u] == low[u])
	{
		color++;
		do
		{
			v = top(), pop();
			vis[v] = 0;
			p[v] = color;
		}
		while(u != v);
	}
}

void cnt_degree()
{
	for(int u = 1; u <= n; u++)
		for(int i = first[u]; i; i = e[i]._next)
		{
			int v = e[i].to;
			if(p[u] != p[v])
			{
				_in[p[v]]++;
				_out[p[u]]++;
			}
		}
	for(int i = 1; i <= n; i++)
		cnt_size[p[i]]++;
}

void make_new_graph()
{
	for(int u = 1; u <= n; u++)
		for(int i = first[u]; i; i = e[i]._next)
		{
			int v = e[u].to;
			if(p[u] != p[v])
				new_Add_Edge(p[u], p[v]);
		}
}

int main()
{
	scanf("%d %d", &n, &m);
	for(rgi i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		Add_Edge(a, b);
	}
	for(int i = 1; i <= n; i++)
		if(!dfn[i])
			Tarjan(i);
	cnt_degree();
	cnt = 0;
	make_new_graph(); 
	for(int i = 1; i <= color; i++)
		if(_out[i] == 0)
		{
			tot++;
			cur = i;
		}
	if(tot == 1)
		printf("%d", cnt_size[cur]);
	else
		printf("0");
	return 0;
}

