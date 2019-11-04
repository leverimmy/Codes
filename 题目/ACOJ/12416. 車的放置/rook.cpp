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
const int N = 200 + 10;
const int M = 200 + 10; 

int n, m, t, cnt, ans;
int a[N][M], first[N];
int vis[N << 1], match[N << 1];

struct edge
{
	int to, _next;
} e[N << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v)
{
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

bool Find(int x)
{
	for(rgi i = first[x]; ~i; i = e[i]._next)
	{
		int y = e[i].to;
		if(!vis[y])
		{
			vis[y] = 1;
			if(match[y] == 0 || Find(match[y]))
			{
				match[y] = x;
				return 1;
			}
		}
	}
	return 0;
}

void Hungary()
{
	for(rgi i = 1; i <= n; ++i)
	{
		memset(vis, 0, sizeof(vis));
		if(Find(i))
			ans++;
	}
}

int main()
{
	n = read(), m = read(), t = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= t; ++i)
	{
		int u = read(), v = read();
		a[u][v] = 1;
	}
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j)
			if(!a[i][j])
				Add_Edge(i, n + j);
	Hungary();
	printf("%d", ans);
	return 0;
}

