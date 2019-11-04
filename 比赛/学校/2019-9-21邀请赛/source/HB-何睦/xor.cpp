#pragma GCC optimize(2)
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
#define MO 1000005
#define NO 200005
#define eps 1e-9
#define P 998244353ll
#define fup(i, _x, _y) for (register int i = _x; i <= _y; ++i)
#define fdn(i, x, y) for (int i = x; i >= y; i--)
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

int f[NO][31], n, m, a0, a1;
//variable

inline int getf(int p, int o)
{
	return f[o][p] == o ? o : f[o][p] = getf(p, f[o][p]);
}
inline void uni(int p, int x, int y)
{
	f[getf(p, y)][p] = getf(p, x);
}
void init()
{
	n = read(), m = read();
	a0 = n << 1 | 1, a1 = a0 + 1, m++;
	fup (i, 1, a1)
		fup (j, 0, 30)
			f[i][j] = i;
	while (--m)
	{
		int x = read() - 1, y = read(), k = read(), xx = x + n, yy = y + n;
		if (!x)
			x = a0, xx = a1;
		fup (j, 0, 30)
		{
			((1 << j) & k) ? (uni(j, x, yy), uni(j, xx, y)) : (uni(j, x, y), uni(j, xx, yy));
			if (getf(j, x) == getf(j, xx) || getf(j, y) == getf(j, yy))
			{
				puts("No");
				while (--m)
					read(), read(), read();
				return;
			}
		}
	}
	puts("Yes");
	return;
}
//functions

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int T = read();
	while (T--)
		init();
	return 0;
}
//main
/*
9 10
1  5
2  6
3  7
4  8
*/ 
