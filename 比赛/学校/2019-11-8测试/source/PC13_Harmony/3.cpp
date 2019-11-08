#include <iostream>
#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <string> 
#include <queue>
#include <cmath>
#include <algorithm>
#define INF 0x3f3f3f3f
#define NO 10005
#define MO 100005
#define fi first
#define se second
#define lln putchar('\n')
#define blk putchar(' ')
#define fup(i, x, y) for(register int i = x; i <= y; ++i)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii;
ll read()
{
	ll ret = 0;
	char ch = ' ', last;
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ret = (ret << 3) + (ret << 1) + ch - '0', ch = getchar();
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

int n, m, cnt, head[NO], t, dfn[NO], low[NO], ans;
struct node
{
	int v, ne;
}e[MO << 1];
// variable

void add(int u, int v)
{
	e[++cnt].ne = head[u];
	e[cnt].v = v;
	head[u] = cnt;
}
void tar(int u, int li)
{
	dfn[u] = low[u] = ++t;
	for (int i = head[u]; i; i = e[i].ne)
		if (i != (li ^ 1))
		{
			if (!dfn[e[i].v])
				tar(e[i].v, i), low[u] = min(low[u], low[e[i].v]);
			else
				low[u] = min(low[u], dfn[e[i].v]);
			if (dfn[u] < low[e[i].v])
				ans++;
		}
}
void init()
{
	memset(head, 0, sizeof(int) * (n + 1));
	if (scanf("%lld", &n) == -1)
		exit(0);
	m = read(), ans = 0, cnt = 1;
	fup (i, 1, m)
	{
		int x = read(), y = read();
		add(x, y), add(y, x);
	}
	fup (i, 1, n)
		if (!dfn[i])
			tar(i, -1);
	write(ans), lln;
}
//functions

int main()
{
	freopen("3.in", "r", stdin);
	freopen("3.out", "w", stdout);
	while (1)
		init();
	return 0;
}
//main 
