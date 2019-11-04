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
const int N = 1000 + 10;
const int M = 1e6 + 10; 

int n, m, _e, cnt, ans;
int first[N], match[N << 1], vis[N << 1];

struct edge
{
	int to, _next;
} e[M];

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
//	freopen("testdata.in", "r", stdin);
//	freopen("testdata.out", "w", stdout);
	n = read(), m = read(), _e = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= _e; ++i)
	{
		int u = read(), v = read();
		if(u > n || v > m)	continue;
		Add_Edge(u, v + n);
	}
	Hungary();
	printf("%d", ans);
	return 0;
}

