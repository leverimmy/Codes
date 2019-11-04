#pragma GCC optimize (2)
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <deque>
#define INF 0x3f3f3f3f
#define MO 200005
#define NO 1005
#define eps 1e-9
#define P 998244353ll
#define fup(i, x, y) for (register int i = x; i <= y; ++i)
#define fdn(i, x, y) for (register int i = x; i >= y; --i)
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
#define ls o << 1
#define  rs o << 1 | 1
#define lln putchar('\n')
#define blk putchar(' ')
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii;
inline ll read()
{
	char ch = ' ', last;
	ll ans = 0;
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ans = ans * 10 + int(ch - '0'), ch = getchar();
	if (last == '-')
		return -ans;
	return ans;
}
void write(ll x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x >= 10)
		write(x / 10);
	putchar(x % 10 + '0');
}
//head

ll n, x[NO], y[NO], f[NO][NO], k;
//variable

inline ll cal(int i, int j)
{
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}
void init()
{
    freopen("transport.in", "r", stdin);
    freopen("transport.out", "w", stdout);
	memset(f, INF, sizeof(f));
	n = read(), k = read();
	fup (i, 1, n)
		x[i] = read(), y[i] = read();
	f[1][0] = 0;
	fup (i, 2, n)
		fup (j, 0, k)
			fup (s, max(0, i - j - 1), i - 1)
				f[i][j] = min(f[i][j], f[s][j - (i - s - 1)] + cal(i, s));
	write(f[n][k]);
}
//functions

int main()
{
	init();
	return 0;
}
//main
