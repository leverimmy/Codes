#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <cstring>
#include <queue>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 500 + 10;
const int M = 1e5 + 10;

int n, m, cnt, ans = -oo, siz, flag;
int first[N], V[N], k[N], dead_time[N];
int to[N][N];

struct edge
{
	int to, _next;
	ll wt;
} e[M << 1];

struct node
{
	int id, tim;
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
	if(a.tim != b.tim)
		return a.tim < b.tim;
	else
		return V[a.id] < V[b.id];
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
	h[siz].tim = val;
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

void bfs()
{
	int vis[N] = {0};
	push(1, 0), dead_time[1] = 0;
	while(siz)
	{
		int x = top().id, cur_time = top().tim;
		pop();
		if(vis[x])	continue;
		vis[x] = 1;
		if(x == n)
		{
			if(V[x] == 0)	printf("%d", cur_time), flag = 1;
			return;
		}
		if(V[x])	continue;
		for(rgi i = 1; i <= k[x]; ++i)	V[to[x][i]]--;
		
		for(rgi i = first[x]; ~i; i = e[i]._next)
		{
			int y = e[i].to;
			if(!vis[y])
				push(y, cur_time + e[i].wt);
		}
	}
}

int main()
{
	freopen("bomb.in", "r", stdin);
	freopen("bomb.out", "w", stdout);
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
			to[i + 1][j] = cur;
		}
	}
	/*for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= k[i]; ++j)
			cout << to[i][j] << " ";
		cout << endl;
	}*/
	bfs();
	if(!flag)
		puts("Mission Failed");
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

