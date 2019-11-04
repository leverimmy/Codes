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
#define NO 1000005
#define eps 1e-9
#define P 1000000007ll
#define fup(i, x, y) for (register int i = x; i <= y; ++i)
#define fdn(i, x, y) for (register int i = x; i >= y; --i)
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
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

ll mul[NO], n, m, k;
//variable

ll fast(ll x, ll y)
{
	ll ret = 1;
	while (y)
	{
		if (y & 1)
			ret = ret * x % P;
		x = x * x % P;
		y >>= 1;
	}
	return ret % P;
}
void init()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	n = read(), m = read(), k = read();
	mul[0] = 1;
	fup (i, 1, n)
		mul[i] = mul[i - 1] * i % P;
	write(mul[n - k] * fast(mul[m - 1], P - 2) % P * fast(mul[n - k - m + 1], P - 2) % P), lln;
}
//functions

int main()
{
	init();
	return 0;
}
//main
