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
#define NO 105
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

int n, K, l[NO], c[NO], a[NO], f[NO][NO][NO], g[NO][NO][NO], book[NO];
//variable

inline void Min(int &f1, int f2, int f3, int &g1, int g2, int g3)
{
	if (f1 > f2 + f3)
		f1 = f2 + f3, g1 = g2 + g3;
	else if(f1 == f2 + f3)
		g1 = max(g1, g2 + g3);
}
void init()
{
	freopen("zuma.in", "r", stdin);
	freopen("zuma.out", "w", stdout);
	memset(f, INF, sizeof(f));
	n = read(), K = read();
	int cur = 0;
	fup (i, 1, n)
	{
		int x = read();
		if (x == c[cur])
			++l[cur];
		else
			c[++cur] = x, ++l[cur];
	}
	n = cur, cur = 0;
	fup (i, 1, n)
		if (!book[c[i]])
			book[c[i]] = ++cur, c[i] = cur;
		else	
			c[i] = book[c[i]];
	fup (i, 1, n)
		f[i][i][0] = max(0, K - l[i]), g[i][i][0] = 0, f[i][i][c[i]] = 0, g[i][i][c[i]] = l[i];
	fup (len, 2, n)
		for (register int i = 1, j = i + len - 1; j <= n; ++i, ++j)
			fup (h, i, j - 1)
				fup (k, 1, cur)
				{
					Min(f[i][j][k], f[i][h][k], f[h + 1][j][k], g[i][j][k], g[i][h][k], g[h + 1][j][k]);
					Min(f[i][j][k], f[i][h][k], f[h + 1][j][0], g[i][j][k], g[i][h][k], g[h + 1][j][0]);
					Min(f[i][j][k], f[i][h][0], f[h + 1][j][k], g[i][j][k], g[i][h][0], g[j + 1][j][k]);
					f[i][j][0] = min(f[i][j][0], min(f[i][h][0] + f[h + 1][j][0], f[i][h][k] + f[h + 1][j][k] + max(0, K - g[i][j][k])));
				}
	write(f[1][n][0]), lln;
}
//functions

int main()
{
	init();
	return 0;
}
// main
/*
f[i][j][k]: ([i,j], color is k)'s answer
g[i][j][k]: ([i,j], color is k)'s len of answer
f[i][j][k] = min(f[i][j][k], f[i][h][k] + f[h + 1][j][0], f[i][h][0] + f[h + 1][j][k], f[i][h][k] + f[h + 1][j][k]), f;
f[i][j][0] = min(f[i][j][0], f[i][h][0] + f[h + 1][j][0], f[i][h][k] + f[h + 1][j][K](len > K)) 



*/
