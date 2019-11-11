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

int n, cnt, out1[NO], out[NO], head[NO];
bool book[NO];
struct node
{
	int ne, v;
}e[MO];
//variable

void add(int u, int v)
{
	e[++cnt].ne = head[u];
	e[cnt].v = v;
	head[u] = cnt;
}
void dfs(int u, bool f)
{
	if (out1[u] > 1 && f)
	{
		out1[u]--;
		return;
	}
	book[u] = true;
	for (int i = head[u]; i; i = e[i].ne)
		dfs(e[i].v, 1);
}
void init()
{
	freopen("catas.in", "r", stdin);
	freopen("catas.out", "w", stdout);
	n = read();
	fup (i, 1, n)
	{
		int x = read();
		while (x)
			out[i]++, add(x, i), x = read();
	}
	fup (i, 1, n)
	{
		memset(book, false, sizeof(int) * (n + 1));
		memcpy(out1, out, sizeof(int) * (n + 1));
		dfs(i, 0);
		int ans = 0;
		fup (j, 1, n)
			ans += book[j];
		write(ans - 1), lln;
	}
}
//function

int main()
{
	init();
	return 0;
}
//main
