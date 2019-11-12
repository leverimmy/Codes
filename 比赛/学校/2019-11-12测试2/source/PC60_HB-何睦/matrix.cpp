#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#define NO 805
#define INF 0x3f3f3f3f
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
#define fup(i, x, y) for (register int i = x; i <= y; ++i)
#define fdn(i, x, y) for (register int i = x; i >= y; --i)
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

int n, m, a[NO][NO], b[NO][NO], prea[NO][NO], preb[NO][NO], x[NO], y[NO];
//variable

void init()
{
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	n = read(), m = read();
	fup (i, 1, n)
		fup (j, 1, n)
			a[i][j] = read();
	fup (i, 1, n)
		fup (j, 1, n)
			b[i][j] = read();
	fup (i, 1, n)
		fup (j, 1, n)
			prea[i][j] = prea[i - 1][j] + a[i][j];
	fup (i, 1, n)
		fup (j, 1, n)
			preb[i][j] = preb[i][j - 1] + b[i][j];
	while (m--)
	{
		ll a1 = read(), b1 = read(), a2 = read(), b2 = read(), ans = 0;
		if (a1 > a2)
			swap(a1, a2);
		if (b1 > b2)
			swap(b1, b2);
		fup (i, 1, n)
			ans += ll(prea[a2][i] - prea[a1 - 1][i]) * (preb[i][b2] - preb[i][b1 - 1]);
		write(ans), lln;
	}
}
//functions

int main()
{
	init();
	return 0;
}
//main
