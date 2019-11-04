#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int
#define rgl register ll

using namespace std;

const int N = 1000 + 10;
const int M = 500000 + 10;

int n, m, t, cnt, ans;
int first[N], vis[N], match[N];

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

int Find(int x)
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
		if(u > n || v > m)
			continue;
		Add_Edge(u, v);
	}
	Hungary();
	printf("%d", ans);
	return 0;
}

