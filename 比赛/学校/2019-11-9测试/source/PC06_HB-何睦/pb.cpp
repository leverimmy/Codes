#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 0x3f3f3f3f
#define NO 105
#define fi first 
#define lln putchar('\n')
#define blk putchar(' ')
#define se second
#define mp(x, y) make_pair(x, y)
#define fup(i, x, y) for (register int i = x; i <= y; i++)
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii;
inline ll read()
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

ll n, a[NO], f[NO][NO], w, pre[NO];
// variable

bool cmp(int i, int j)
{
	return i > j;
}
void init()
{
	freopen("pb.in", "r", stdin);
	freopen("pb.out", "w", stdout);
	memset(f, INF, sizeof(f));
	f[0][0] = 0;
	n = read(), w = read();
	fup (i, 1, n)
		a[i] = read();
	sort(a + 1, a + n + 1, cmp);
	fup (i, 1, n)
		pre[i] = pre[i - 1] + a[i];
	fup (k, 1, w)
	{
		fup (i, 1, n)
			fup (j, 0, i - 1)
				f[k][i] = min(f[k][i], f[k - 1][j] + (pre[i] - pre[j]) * ll(i));
//		fup (i, 1, n)
//			cout << f[k][i] << ' ';
//		lln;
	}
	printf("%.4f", f[w][n] / db(pre[n])), lln;
}
// functions

int main()
{
	init();
	return 0;
}
// main
