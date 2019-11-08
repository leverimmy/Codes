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
#define NO 1000005
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


int n, m, cnt, head[NO], nex[NO], ans;
bool book[NO];
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
bool dfs(int u)
{
	if (book[u])
		return false;
	book[u] = true;
	for (int i = head[u]; i; u = e[i].ne)
	{
		if (!nex[e[i].v] || dfs(nex[e[i].v]))
		{
			nex[e[i].v] = u;
			return true;
		}
	}
	return false;
}
void init()
{
	memset(head, 0, sizeof(int) * (n + 1));
	memset(nex, 0, sizeof(int) * (n + 1));
	if (scanf("%lld", &n) == -1)
		exit(0);
	m = read(), ans = cnt = 0;
	fup (i, 1, m)
	{
		int x = read(), y = read();
		add(x, y);
	}
	fup (i, 1, n)
		memset(book, false, sizeof(bool) * (n + 1)), ans += dfs(i);
	write(ans), lln;
}
//functions

int main()
{
	freopen("8.in", "r", stdin);
	freopen("8.out", "w", stdout);
	while (1)
		init();
	return 0;
}
//main
