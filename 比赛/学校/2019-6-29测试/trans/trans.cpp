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
#define inf 0x3f3f3f3f
#define maxn 4010
#define maxm 1000010 << 1

using namespace std;

int n, m, s, t, cnt, ans = inf, vis[maxn];
int first[maxn];

struct edge
{
	int to, _next, p, q;
} e[maxm];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int p, int q)
{
	e[++cnt].to = v;
	e[cnt].p = p;
	e[cnt].q = q;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

void dfs(int cur, int time)
{
	if(time >= ans)
		return;
	if(cur == t)
	{
		ans = min(time, ans);
		return;
	}
	for(rgi i = first[cur]; i; i = e[i]._next)
	{
		int	x = e[i].to;
		if(vis[x])
			continue;
		vis[x] = 1;
		int len = e[i].p + e[i].q;
		if(time % len < e[i].p)//the road isn't closed
		{
			dfs(x, time + 1);
			vis[x] = 0;
		}
		else//the road is closed
		{
			int left = len - time % len;
			dfs(x, time + left + 1);
			vis[x] = 0;
		}
	}
}

int main()
{
	n = read(), m = read();
	s = read(), t = read();
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read(), p = read(), q = read();
		Add_Edge(u, v, p, q);
		Add_Edge(v, u, p, q);
	}
	dfs(s, 0);
	printf("%d", ans);
	return 0;
}

