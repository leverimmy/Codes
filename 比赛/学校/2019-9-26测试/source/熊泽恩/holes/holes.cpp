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

int n, m, k, ans = oo;
int cnt, first[N];
int hole[N], vis[N], dis[N];

struct edge
{
	int to, _next;
} e[M << 1];

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

int dfs(int x)
{
	if(hole[x])	return 0;
	int res = oo;
	for(rgi i = first[x]; ~i; i = e[i]._next)
	{
		int y = e[i].to;
		if(vis[y])	continue;
		vis[y] = 1;
		res = min(res, dfs(y));
		vis[y] = 0;
	}
	return dis[x] = res + 1;
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
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	if(n <= 10)//point1
	{
		for(rgi state = 0; state < (1 << n) - 1; ++state)
		{
			if(__builtin_popcountl(state) != k)	continue;
			memset(hole, 0, sizeof(hole));
			memset(dis, 0, sizeof(dis));
			int tmp = 0;
			for(rgi i = 1; i <= n; ++i)	if(state & (1 << i - 1)) hole[i] = 1;
			for(rgi i = 1; i <= n; ++i)
			{
				vis[i] = 1;
				dis[i] = dfs(i);
				vis[i] = 0;
			}
			for(rgi i = 1; i <= n; ++i)	tmp = max(tmp, dis[i]);
			ans = min(ans, tmp);
		}
		printf("%d", ans);
	}
	else//point2
	{
		if(m == n - 1)
		{
			
		}
		else
		{
			
		}
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
