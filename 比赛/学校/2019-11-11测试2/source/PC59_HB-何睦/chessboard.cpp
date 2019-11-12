#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3fll
#define NO 100005
#define MO 105
#define KO 3505
#define lln putchar('\n')
#define blk putchar(' ')
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
#define fup(i, x, y) for (register int i = x; i <= y; ++i)
#define fdn(i, x, y) for (register int i = x; i >= y; --i)
using namespace std;
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

int n, a[KO][MO][MO], t, m, k;
//variable

void init()
{
	freopen("chessboard.in", "r", stdin);
	freopen("chessboard.out", "w", stdout);
	n = read(), k = read(), m = read();
	fup (i, 1, n)
		fup (j, 1, n)
			a[1][i][j] = 1;
	int cnt = 1;
	while (m--)
	{
		char ch = getchar();
		while (ch == ' ' || ch == '\n' || ch == '\r')
			ch = getchar();
		if (ch == 'L')
		{
			int id = read();
			memcpy(a[cnt], a[id], sizeof(a[id]));
		}
		else if (ch == 'S')
		{
			getchar(), getchar(), getchar();
			cnt++, memcpy(a[cnt], a[cnt - 1], sizeof(a[cnt - 1]));
		}
		else
		{
			int c = read(), x = read() + 1, y = read() + 1, xx = read() + 1, yy = read() + 1;
			fup (i, x, xx)
				fup (j, y, yy)
				{
					if (!(((i - x) & 1) ^ ((j - y) & 1)))
						a[cnt][i][j] = c;
		//			cout << i << ',' << j << ',' << ((i - x) & 1) << ' ' << ((j - y) & 1) << endl;
				}
		}
	}
	fup (i, 1, n)
	{
		fup (j, 1, n)
			write(a[cnt][i][j]), blk;
		lln;
	}
}
//functions

int main()
{
	init();
	return 0;
}
// main

