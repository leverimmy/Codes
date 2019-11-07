#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#define NO 405
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

int n, m, S, f[2][NO][NO], v[NO][NO], w[NO][NO];
// variable 

void init()
{
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	memset(f, -INF, sizeof(f));	
	n = read(), m = read(), S = read();
	fup (i, 1, n)
		fup (j, 1, m)
			v[i][j] = read();
	fup (i, 1, n)
		fup (j, 1, m)
			w[i][j] = read();
	int ans = -INF;
	fup (i, 1, n)
	{
		memcpy(f[0], f[1], sizeof(f[1]));
		memset(f[1], -INF, sizeof(f[1]));
		if (i == 1)
			f[1][1][v[1][1]] = w[1][1];
		fup (j, 1, m)
			fup (k, v[i][j], S)
			{
				if (i == 1 && j == 1)
					continue;
//				cout << i << ',' << j << ',' << k << ',' << v[i][j] << ':' << endl;
				if (i > 1)
					f[1][j][k] = max(f[1][j][k], f[0][j][k - v[i][j]] + w[i][j]), f[1][j][k] = max(f[1][j][k], f[0][j][k]);//, cout << "!" << f[0][j][k - v[i][j]] + w[i][j] << ',';
				if (j > 1)
					f[1][j][k] = max(f[1][j][k], f[1][j - 1][k - v[i][j]] + w[i][j]), f[1][j][k] = max(f[1][j][k], f[1][j - 1][k]);//, cout <<"!!"<<f[1][j - 1][k - v[i][j]] + w[i][j] << ',';
	//			lln;
				ans = max(ans, f[1][j][k]);
			}
	}
	write(ans), lln;
}
// functions

int main()
{
	init();
	return 0;
}
// main
/*
3 4 5
1 2 1 1
2 3 1 2
3 2 2 2
2 3 4 2
1 4 5 1
10 1 2 1

*/
