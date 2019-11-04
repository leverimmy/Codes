#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 200100
#define maxm 500100 << 1

using namespace std;

const int inf = 0x3fffffff;

int n, m, b, cnt, siz, l = inf, r = -inf, ans;
int first[maxn], dis[maxn], f[maxn];

struct edge
{
	int to, _next, wt;
} e[maxm];

struct node
{
	int id;
	int val;
} h[maxn];

bool operator <(const struct node &a, const struct node &b)
{
	return a.val > b.val;
}

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int w)
{
	e[++cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

priority_queue <struct node> q;

bool check(int val)
{
	for(rgi i = 1; i <= n; ++i)
		dis[i] = inf;
	q.push((node)
	{
		1, 0
	});
	dis[1] = 0;
	while(!q.empty())
	{
		int x = q.top().id;
		int cur = q.top().val;
		q.pop();
		if(dis[x] != cur)
			continue;
		for(rgi i = first[x]; i; i = e[i]._next)
		{
			int y = e[i].to;
			if(f[y] <= val && dis[y] > dis[x] + e[i].wt)
			{
				dis[y] = dis[x] + e[i].wt;
				q.push((node)
				{
					y, dis[y]
				});
			}
		}
	}
	if(dis[n] <= b)
		return 1;
	else
		return 0;
}

int main()
{
	n = read(), m = read(), b = read();
	for(rgi i = 1; i <= n; ++i)
	{
		f[i] = read();
		l = min(l, f[i]);
		r = max(r, f[i]);
	}
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read(), w = read();
		if(u == v)
			continue;
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);
	}
	if(!check(inf))
		puts("AFK");
	else
	{
		while(l <= r)
		{
			int mid = (l + r) >> 1;
			if(check(mid))
			{
				ans = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		printf("%d", ans);
	}
	return 0;
}

