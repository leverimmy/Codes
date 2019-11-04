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
#define maxn 2010
#define maxm 500010

using namespace std;

int n, m, A, B, C, cnt, siz;
int first[maxn], dis[maxn], vis[maxn], arr[maxn];
int x[maxn], y[maxn], p[maxn], q[maxn];

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
	e[cnt]._next = first[u];
	e[cnt].p = p;
	e[cnt].q = q;
	first[u] = cnt;
}

int SPFA(int s)
{
	int l = 0, r = 1;
	dis[s] = 0;
	vis[s] = 1;
	arr[r] = s;
	while (l < r)
	{
		l++;
		int x = arr[l];
		vis[x] = 0;
		for (rgi i = first[x]; i; i = e[i]._next)
		{
			int y = e[i].to;
			if (e[i].p < dis[x])
				continue;
			if (dis[y] > e[i].q)
			{
				dis[y] = e[i].q;
				if (!vis[y])
				{
					r++;
					arr[r] = y;
					vis[y] = 1;
				}
			}
		}
	}
}

int main()
{
	freopen("route.in", "r", stdin);
	freopen("route.out", "w", stdout);
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	n = read(), m = read(), A = read(), B = read(), C = read();
	for(rgi i = 1; i <= m; ++i)
	{
		x[i] = read();
		y[i] = read();
		p[i] = read();
		q[i] = read();
	}
	if(m == n - 1)
	{
		int ans = 0, time = 0;
		for(rgi i = 0; i <= m - 1; ++i)
		{
			int t = p[i + 1] - q[i];
			time += t;
			time += q[i] - p[i];
			ans += A * t * t + B * t + C;
		}
		time += q[m] - p[m];
		printf("%d", ans + time);
	}
	else if(A == 0 && B == 0 && C == 0)
	{
		for(rgi i = 1; i <= m; ++i)
			Add_Edge(x[i], y[i], p[i], q[i]);
		SPFA(1);
		printf("%d", dis[n]);
	}
	return 0;
}

