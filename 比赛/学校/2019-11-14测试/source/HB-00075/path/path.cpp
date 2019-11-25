#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
#define NO 200005
#define INF 0x3f3f3f3fll
#define lln putchar('\n')
#define blk putchar(' ')
#define fi first
#define se second
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii;
inline ll read()
{
	ll ret = 0;
	char ch = ' ', last;
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ret = ((ret + (ret << 2)) << 1) + (ch ^ '0'), ch = getchar();
	return last == '-' ? -ret : ret; 
}
void write(ll x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}
// head

int n, m, Q, cnt, head[NO], num[NO], la[NO], lap[NO], sel;
ll dis[3][NO], ond[NO];
priority_queue<pii, vector<pii>, greater<pii> > q;
bool book[NO];
struct node
{
	int v, c, ne;
}e[NO << 1];
// variable

void add(int u, int v, int c)
{
	e[++cnt].ne = head[u];
	e[cnt].v = v;
	e[cnt].c = c;
	head[u] = cnt;
}
ll dij(int s, int t, int f)
{
	for (register int i = 1; i <= n; i++)
		dis[f][i] = INF * INF, book[i] = false;
	dis[f][s] = 0, q.push(mp(0, s));
	while (!q.empty())
	{
		int u = q.top().se;
		q.pop();
		if (book[u])
			continue;
		book[u] = true;
		for (int i = head[u]; i; i = e[i].ne)
			if (dis[f][e[i].v] > dis[f][u] + e[i].c && !ond[i])
				dis[f][e[i].v] = dis[f][u] + e[i].c, la[e[i].v] = i, lap[e[i].v] = u, q.push(mp(dis[f][e[i].v], e[i].v));
	}
	if (!f)
	{
		int u = t;
		while (u != s)
			ond[la[u]] = true, u = lap[u];
	}
	return dis[f][n];
}
void init()
{
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
	n = read(), m = read(), Q = read(), cnt = 1;
	for (int i = 1; i <= m; ++i)
	{
		int x = read(), y = read(), z = read();
		add(x, y, z), add(y, x, z), num[i] = cnt;
	}
	if (Q <= 10 || (n <= 100 && m <= 100))
	{
		while (Q--)
		{
			int nu = read(), x = read(), i = num[nu], la = e[i].c;
			e[i].c = e[i ^ 1].c = x;
			write(dij(1, n, 1)), lln;
			e[i].c = e[i ^ 1].c = la;
		}
		return;
	}
	dij(n, 1, 1), dij(1, n, 0), dij(1, n, 2);
	while (Q--)
	{
		int nu = read(), x = read(), i = num[nu];
		write(min(dis[0][n], min(dis[0][e[i].v] + x + dis[1][e[i ^ 1].v], dis[0][e[i ^ 1].v] + x + dis[1][e[i].v]))), lln;
	}
}
// functions

int main()
{
	init();
	return 0;
}
// main
