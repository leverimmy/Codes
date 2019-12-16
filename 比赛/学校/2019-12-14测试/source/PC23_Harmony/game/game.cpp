#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#define NO 25
#define INF 0x3f3f3f3fll
#define P 998244353ull
#define MO 10005
#define mp(x, y) make_pair(x, y)
#define fi first
#define lln putchar('\n')
#define blk putchar(' ')
#define se second
#define fup(i, x, y) for (register int i = x; i <= y; ++i)
#define fdn(i, x, y) for (register int i = x; i >= y; --i)
using namespace std;
typedef unsigned long long ull;
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

int n, a[NO], s;
bool book[NO][MO], f[NO][MO];
// variable

bool dfs(int u, int s)
{
	if (u == (n << 1 | 1))
		u = 1;
	if (!s)
		return false;
	if (book[u][s])
		return f[u][s];
	book[u][s] = true;
	bool ret = 0;
	fup (i, 1, min(a[u], s))
		ret |= dfs(u + 1, s - i) ^ 1;
	f[u][s] = ret;
	return ret;
}
void init()
{
	memset(book, false, sizeof(book));
	n = read();
	if (!n)
		exit(0);	
	s = read() - 1;
	fup (i, 1, n << 1)
		a[i] = read();
	puts(dfs(1, s) ? "1" : "0");
}
// function

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	while (1)
		init();
	return 0;
}
// main
