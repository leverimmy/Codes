#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
#define NO 100005
#define MO 1000005
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
#define fup(i, x, y) for(register int i = x; i <= y; ++i)
#define lln putchar('\n')
#define blk putchar(' ')
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
ll read()
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
//head

int n, cnt, head[NO], f[NO], g[NO], s, f2[NO], to[NO], ans;
struct node
{
	int ne, v, c;
}e[MO];
//variable

void add(int u, int v, int c)
{
	e[++cnt].ne = head[u];
	e[cnt].v = v;
	e[cnt].c = c;
	head[u] = cnt;
}
void dfs1(int u, int la)
{
	for (int i = head[u]; i; i = e[i].ne)
		if (e[i].v != la)
		{
			dfs1(e[i].v, u);
			if (f[e[i].v] + e[i].c > f[u])
				f2[u] = f[u], f[u] = f[e[i].v] + e[i].c, to[u] = e[i].v;
			else
				f2[u] = max(f2[u], f[e[i].v] + e[i].c);
		}
}
void dfs2(int u, int la, int li)
{
	g[u] = max(g[la], (to[la] == u ? f2[la] : f[la])) + e[li].c;
	for (int i = head[u]; i; i = e[i].ne)
		if (e[i].v != la)
			dfs2(e[i].v, u, i);
}
void init()
{
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
	n = read();
	fup (i, 1, n - 1)
	{
		int x = read(), y = read(), z = read();
		add(x, y, z), add(y, x, z), s += z;
	}
	dfs1(1, 0), dfs2(1, 0, 0);
	fup (i, 1, n)
	{
		int x = read();
		if (x)
			ans = max(ans, max(f[i], g[i]));
	}
	write(s * 2 - ans), lln;
}
//function

int main()
{
	init();
	return 0;
}
//main
/*
5
1 2 1
1 3 1
3 4 3
3 5 4
1 1 1 0 0

*/
