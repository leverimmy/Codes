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
#define lln putchar('\n')
#define blk putchar(' ')
#define NO 2000005
#define fi first 
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

int n, a[NO], f[2][NO], c[NO], cnt, d[NO];
// variable

void add(int p, int x)
{
	for (int i = p; i <= n; i += (i & -i))
		d[i] = max(d[i], x);
}
int ask(int p)
{
	int ret = 0;
	for (int i = p; i; i -= (i & -i))
		ret = max(ret, d[i]);
	return ret;
}
void init()
{
	freopen("gfw.in", "r", stdin);
	freopen("gfw.out", "w", stdout);
	n = read();
	fup (i, 1, n)
		c[i] = a[i] = read();
	sort(c + 1, c + n + 1);
	cnt = unique(c + 1, c + n + 1) - c - 1;
	f[0][1] = 1;
	fup (i, 2, n)
	{
		if (a[i] > a[i - 1])
		{
			f[0][i] = f[0][i - 1] + 1;
			if (f[1][i - 1])
				f[1][i] = f[1][i - 1] + 1;
		}
		else
			f[0][i] = 1;
		int pos = lower_bound(c + 1, c + n + 1, a[i]) - c, Max = ask(pos - 1);
		if (Max)
			f[1][i] = max(f[1][i], Max + 1);
		add(pos, f[0][i]);
	}
	int ans = 0;
	fup (i, 1, n)
		ans = max(ans, max(f[0][i], f[1][i]));
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
9
5 3 4 9 2 8 6 7 1

*/
