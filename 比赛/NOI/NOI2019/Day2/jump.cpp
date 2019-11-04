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
#define maxn 50010
#define maxm 100010

using namespace std;

int n, m, W, H, cnt, siz;
int first[maxm], vis[maxn], dis[maxn];

struct edge
{
	int to, _next, wt;
} e[maxm];

struct node
{
	int id, d;
} h[maxn];

struct city
{
	int x, y;
} b[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void push(int num, int val)
{
	h[++siz].id = num;
	h[siz].d = val;
	int cur = siz;
	while(cur >= 1)
	{
		if(h[cur].d < h[cur >> 1].d)
			swap(h[cur], h[cur >> 1]);
		else
			break;
		cur >>= 1;
	}
}

void pop()
{
	swap(h[1], h[siz]);
	h[siz].id = 0;
	h[siz--].d = 0;
	int cur = 1;
	while((cur << 1) <= siz)
	{
		int lc = cur << 1, rc = lc + 1, nxt;
		if(rc <= siz)
		{
			if(h[lc].d <= h[rc].d)
				nxt = lc;
			else
				nxt = rc;
		}
		else
			nxt = lc;
		if(h[nxt].d < h[cur].d)
		{
			swap(h[nxt], h[cur]);
			cur = nxt;
		}
		else
			break;
	}
}

struct node top()
{
	return h[1];
}

void Add_Edge(int u, int v, int w)
{
	e[++cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

void Dijkstra(int s)
{
	dis[s] = 0;
	push(s, 0);
	while(siz)
	{
		int x = top().id;
		pop();
		if(vis[x])
			continue;
		vis[x] = 1;
		for(rgi i = first[x]; i; i = e[i]._next)
		{
			int y = e[i].to;
			if(dis[y] > dis[x] + e[i].wt)
			{
				dis[y] = dis[x] + e[i].wt;
				push(y, dis[y]);
			}
		}
	}
}

bool cmp(struct city a, struct city b)
{
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int Find(int now_x, int now_y)
{
	int l = 2, r = n, ans;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(b[mid].x >= now_x)
			l = mid + 1;
		else
			r = mid - 1;
		ans = mid;
	}
	return ans;
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	memset(dis, 0x3f, sizeof(dis));
	n = read(), m = read(), W = read(), H = read();
	for(rgi i = 1; i <= n; ++i)
	{
		b[i].x = read();
		b[i].y = read();
	}
	int startx = b[1].x, starty = b[1].y;
	sort(b + 1, b + n + 1, cmp);
	for(rgi i = 1; i <= m; ++i)
	{
		int cur_p = read();
		int cur_t = read();
		int cur_L = read();
		int cur_R = read();
		int cur_D = read();
		int cur_U = read();
		if(cur_L == startx && cur_D == starty)
			continue;
		Add_Edge(cur_p, Find(cur_L, cur_D), cur_t);
	}
	Dijkstra(1);
	for(rgi i = 2; i <= n; ++i)
		printf("%d\n", dis[i]);
	return 0;
}

