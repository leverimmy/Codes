#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
//#include <queue>
#define il inline
#define rgi register int
#define rgl register long long
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, m, cnt, ans = oo;
int first[N];

struct edge
{
	int to, _next, wt, vis;
} e[M << 1];

/*struct node
{
	int id, cur_ans;
};

queue <struct node> q;*/

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int w)
{
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt].vis = 0;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void dfs(int x, int cur_ans)
{
	if(cur_ans > 0 && x == 1 && cur_ans < ans)
	{
		ans = cur_ans;
		return;
	}
	if(cur_ans >= ans)
		return;
	for(rgi i = first[x]; ~i; i = e[i]._next)
	{
		if(e[i].vis || e[i ^ 1].vis)
			continue;
		int y = e[i].to;
		e[i].vis = e[i ^ 1].vis = 1;
		dfs(y, cur_ans + e[i].wt);
		e[i].vis = e[i ^ 1].vis = 0;
	}
}

/*void bfs()
{
	q.push((node){1, 0});
	while(!q.empty())
	{
		struct node x = q.front();
		q.pop();
		if(x.cur_ans > 0 && x.id == 1)
		{
			if(x.cur_ans < ans)
				ans = x.cur_ans;
			return;
		}
		if(x.cur_ans >= ans)
			continue;
		for(rgi i = first[x.id]; ~i; i = e[i]._next)
		{
			if(e[i].vis || e[i ^ 1].vis)
				continue;
			e[i].vis = e[i ^ 1].vis = 1;
			q.push((node){e[i].to, e[i].wt + x.cur_ans});
		}
	}
}*/

int main()
{
//	freopen("patrol.in", "r", stdin);
//	freopen("patrol.out", "w", stdout);
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read(), w1 = read(), w2 = read();
		Add_Edge(u, v, w1);
		Add_Edge(v, u, w2);
	}
//	bfs();
	dfs(1, 0);
	if(ans == oo)
		puts("-1");
	else
		printf("%d", ans); 
	return 0;
}
/*
4 5
1 2 5 3
1 3 1 1
1 4 4 7
2 3 5 7
4 3 6 4

3 3
1 2 3 7
2 3 1 4
2 3 4 3

*/

