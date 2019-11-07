#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#define NO 100005
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define lln putchar('\n')
#define blk putchar(' ')
#define mp(x, y) make_pair(x, y)
#define fup(i, x, y) for(register int i = x; i <= y; ++i)
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

int n, m, x[NO], y[NO], a[NO], b[NO], ans;
bool book[NO];
// variable 

void dfs(int now)
{
	if (now == m + 1)
	{
		fup (i, 1, n)
			b[i] = a[i];
		fup (i, 1, m)
			if (book[i])
				swap(b[x[i]], b[y[i]]);
		fup (i, 1, n)
			fup (j, i + 1, n)
				ans += (b[i] > b[j]);
	}
	else
		book[now] = 1, dfs(now + 1), book[now] = 0, dfs(now + 1);
}
void init()
{
	freopen("inversion.in", "r", stdin);
	freopen("inversion.out", "w", stdout);
	n = read(), m = read();
	fup (i, 1, n)
		a[i] = read();
	fup (i, 1, m)
		x[i] = read(), y[i] = read();
	dfs(1);
	printf("%.8f", ans / db(1 << m)), lln;
}
// functions

int main()
{
	init();
	return 0;
}
// main
