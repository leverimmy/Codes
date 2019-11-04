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
const int M = 50000 + 10;

int n, m, cnt, ans;
int first[N], vis[N << 1], match[N << 1], a[N][N];

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
		if(vis[y])
			continue;
		vis[y] = 1;
		if(!match[y] || Find(match[y]))
		{
			match[y] = x;
			return 1;
		}
	}
	return 0;
}

void Hungary()
{
	for(rgi i = 1; i <= n; ++i)
	{
		if(!match[i])
		{
			memset(vis, 0, sizeof(vis));
			ans += Find(i);
		}
	}
}

int main()
{
//	freopen("travel8.in", "r", stdin);
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		a[u][v] = 1;
	}
	for(rgi k = 1; k <= n; ++k)
		for(rgi i = 1; i <= n; ++i)
			for(rgi j = 1; j <= n; ++j)
				if(i != j && j != k && k != i)
					a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= n; ++j)
			if(a[i][j])
				Add_Edge(i, j + n);
	Hungary();
	printf("%d", n - ans); 
	return 0;
}

