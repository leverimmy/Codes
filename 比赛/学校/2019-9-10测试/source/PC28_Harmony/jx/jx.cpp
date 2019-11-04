#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#define NO 2000005
#define INF 0x3f3f3f3f
#define fi first
#define se second 
#define lln putchar('\n')
#define blk putchar(' ')
#define mp(x, y) make_pair(x, y)
#define fup(i, x, y) for (int i = x; i <= y; i++)
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii;
typedef pair<pair<int, int>, pair<int, int> >piii;
ll read()
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
void write(ll x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x >= 10)
		write(x / 10);
	putchar(x % 10 + '0');
}
//head

ll dp[3][NO], n, a[NO], MAX[3], ans;
//variable

void init()
{
	freopen("jx.in", "r", stdin);
	freopen("jx.out", "w", stdout);
	n = read();
	fup (i, 1, n)
		a[i] = read();
	memset(dp, -INF, sizeof(dp));
	memset(MAX, -INF, sizeof(MAX));
	fup (i, 1, n)
	{
		fup (j, 0, min(i - 1, 2))
		{
			if (!j || j != i - 1)
				dp[j][i] = (i == 1 || dp[j][i - 1] < 0) ? a[i] : dp[j][i - 1] + a[i];
			if (j)
				dp[j][i] = max(a[i] + MAX[j - 1], dp[j][i]);
		}
		fup (j, 0, min(i - 1, 2))
			MAX[j] = max(MAX[j], dp[j][i]);
	}
	fup (i, 0, 2)
		ans = max(ans, MAX[i]);
	write(ans), lln;
}
//functions

int main()
{
	init();
	return 0;
}
//main
