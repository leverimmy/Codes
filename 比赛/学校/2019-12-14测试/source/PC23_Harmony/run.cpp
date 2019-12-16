#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#define NO 1000005
#define INF 0x3f3f3f3fll
#define MO 10005
#define mp(x, y) make_pair(x, y)
#define fi first
#define lln putchar('\n')
#define blk putchar(' ')
#define se second
#define fup(i, x, y) for (register int i = x; i <= y; ++i)
#define fdn(i, x, y) for (register int i = x; i >= y; --i)
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
inline ll read()
{
    ll ret = 0;
    char ch = ' ', last;
    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9')
        ret = (((ret << 2) + ret) << 1) + ch - '0', ch = getchar();
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

int n, m, f[NO][30], cnt, head[NO], fa[NO], d[NO], Max[NO][30];
struct ed
{
    int u, v, c;
}E[NO];
struct node
{
    int v, c, ne;
}e[NO];
// variable

bool cmp(ed i, ed j)
{
    return i.c < j.c;
}
inline int getf(int o)
{
    return o == fa[o] ? o : fa[o] = getf(fa[o]);
}
void add(int u, int v, int c)
{
    e[++cnt].ne = head[u];
    e[cnt].v = v;
    e[cnt].c = c;
    head[u] = cnt;
}
void dfs(int u, int la)
{
	f[u][0] = la, d[u] = d[la] + 1;
	fup (i, 1, log2(d[u]))
		f[u][i] = f[f[u][i - 1]][i - 1], Max[u][i] = max(Max[u][i - 1], Max[f[u][i - 1]][i - 1]);
	for (register int i = head[u]; i; i = e[i].ne)
		if (e[i].v != la)
			Max[e[i].v][0] = e[i].c, dfs(e[i].v, u);
}
int lca(int x, int y)
{
	int ret = 0;
	if (d[x] > d[y])
		swap(x, y);
	fdn (i, log2(d[y]), 0)
		if ((1 << i) & (d[y] - d[x]))
			ret = max(ret, Max[y][i]), y = f[y][i];
	if (x == y)
		return ret;
	fdn (i, log2(d[x]), 0)
		if (f[x][i] != f[y][i])
			ret = max(max(ret, Max[x][i]), Max[y][i]), x = f[x][i], y = f[y][i];
	return ret;
}
void init()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
    n = read(), m = read();
    fup (i, 1, m)
        E[i] = ed{ read(), read(), read() };
    sort(E + 1, E + m + 1, cmp);
    fup (i, 1, n)
        fa[i] = i;
    fup (i, 1, m)
        if (getf(E[i].u) != getf(E[i].v))
            fa[getf(E[i].u)] = getf(E[i].v), add(E[i].u, E[i].v, E[i].c), add(E[i].v, E[i].u, E[i].c);//, cout << E[i].u << ',' << E[i].v << ',' << E[i].c << endl;
    dfs(1, 0);
    int q = read();
   	while (q--)
   	{
   		int x = read(), y = read();
   		write(lca(x, y)), lln;
   	}
}
// function

int main()
{
	init();
	return 0;
}
// main
/*
4 6
1 2 3
1 3 5
2 4 1
3 4 2
4 1 3
2 3 7
3
2 4
2 3
1 4
*/
