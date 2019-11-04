#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 10010
#define maxm 10010

using namespace std;

int n, cnt, cur;
int first[maxn], dis[maxn];

struct edge
{
	int to, _next;
} e[maxm << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v)
{
	e[++cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

void dfs(int x)
{
	for(rgi i = first[x]; i; i = e[i]._next)
		if(!dis[e[i].to])
		{
			dis[e[i].to] = dis[x] + 1;
			dfs(e[i].to);
		}
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n - 1; ++i)
	{
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	dfs(1);
	for(rgi i = 1; i <= n; ++i)
		if(dis[i] > dis[cur])
			cur = i;
	memset(dis, 0, sizeof(dis));
	dfs(cur);
	for(rgi i = 1; i <= n; ++i)
		if(dis[i] > dis[cur])
			cur = i;
	printf("%d", dis[cur]);
	return 0;
}

