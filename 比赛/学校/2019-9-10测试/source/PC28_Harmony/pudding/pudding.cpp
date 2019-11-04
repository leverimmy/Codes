#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#define NO 100005
#define INF 0x3f3f3f3f
#define fi first
#define se second 
#define lln putchar('\n')
#define blk putchar(' ')
#define mp(x, y) make_pair(x, y)
#define fup(i, x, y) for (register int i = x; i <= y; ++i)
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii;
inline ll read()
{
	char ch = ' ', last;
	ll ret = 0;
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ret = (ret << 3) + (ret << 1) + ch - '0', ch = getchar();
	if (last == '-')
		return -ret;
	return ret;
}
inline void write(ll x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x >= 10)
		write(x / 10);
	putchar(x % 10 + '0');
}
//head

int n, m, a[NO], ans, b[NO], cnt, ty, x, y;
//variable

inline void init()
{
	freopen("pudding.in", "r", stdin);
	freopen("pudding.out", "w", stdout);
	n = read(), m = read();
	fup (i, 1, n)
		a[i] = read(), ans = ans + (a[i] != a[i - 1]), a[i] != a[i - 1] && (b[++cnt] = a[i]);
	memcpy(a, b, sizeof(int) * (cnt + 1)), n = cnt;
	while (m--)
	{
		ty = read();
		if (ty - 1)
			write(ans), lln;
		else
		{
			x = read(), y = read(), ans = 0, cnt = 0;
			fup (i, 1, n)
				a[i] = (a[i] == x) ? y : a[i], ans = ans + (a[i] != a[i - 1]), a[i] != a[i - 1] && (b[++cnt] = a[i]);
			memcpy(a, b, sizeof(int) * (cnt + 1)), n = cnt;
		}
	}
}
//functions

int main()
{
	init();
	return 0;
}
//main
