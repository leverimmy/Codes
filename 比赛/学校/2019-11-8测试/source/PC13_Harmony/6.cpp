#include <iostream>
#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <string> 
#include <queue>
#include <cmath>
#include <vector>
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

int n, m, cnt, head[NO], dis[NO];
struct node
{
	int v, ne, c;
}e[MO << 1];
priority_queue<pii, vector<pii>, greater<pii> > q;
bool book[NO];
// variable

void dij()
{
	memset(book, false, sizeof(bool) * (n + 1));
	memset(dis, INF, sizeof(int) * (n + 1));
	q.push(mp(0, 1)), dis[1] = 0;
	while (!q.empty())
	{
		int u = q.top().se;
		q.pop();
		if (book[u])
			continue;
		book[u] = true;
		for (int i = head[u]; i; i = e[i].ne)
			if (!book[e[i].v] && dis[u] + e[i].c < dis[e[i].v])
				dis[e[i].v] = dis[u] + e[i].c, q.push(mp(dis[e[i].v], e[i].v));
	}
	return;
}
void add(int u, int v, int c)
{
	e[++cnt].ne = head[u];
	e[cnt].v = v;
	e[cnt].c = c;
	head[u] = cnt;
}
void init()
{
	memset(head, 0, sizeof(int) * (n + 1));
	if (scanf("%lld", &n) == -1)
		exit(0);
	m = read(), cnt = 0;
	fup (i, 1, m)
	{
		int x = read(), y = read(), z = read();
		add(x, y, z);
	}
	dij(), write(dis[n]), lln;
}
//functions

int main()
{
	freopen("6.in", "r", stdin);
	freopen("6.out", "w", stdout);
	while (1)
		init();
	return 0;
}
//main
