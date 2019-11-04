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
#define NO 205
#define eps 1e-9
#define P 998244353ll
#define fup(i, x, y) for (ll i = x; i <= y; i++)
#define fdn(i, x, y) for (ll i = x; i >= y; i--)
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

int n, m, q, a[NO][NO];
//variable

void init()
{
	freopen("geometry.in", "r", stdin);
	freopen("geometry.out", "w", stdout);
	memset(a, -1, sizeof(a));
	n = read(), m = read(), q = read();
	fup (i, 1, m)
	{
		int x, y;
		char ch;
		x = read(), ch = getchar(), y = read();
		if (ch == 'p' && a[x][y] && a[y][x])
			a[x][y] = 1, a[y][x] = 1;
		else if (ch == 'v' && a[x][y] != 1 && a[y][x] != 1)
			a[x][y] = 0, a[y][x] = 0;
		else
			puts("There must be something wrong!"), exit(0);
	}
	fup (k, 1, n)
		fup (i, 1, n)
			fup (j, 1, n)
				if (i != j && j != k && i != k)
				{
					if (~a[i][k] && ~a[k][j])
					{
						bool cur = !(a[i][k] ^ a[k][j]);
						if (a[i][j] == -1 || a[i][j] == cur)
							a[i][j] = cur;
						else
							puts("There must be something wrong!"), exit(0);
					}
				}
	int cnt = 0;
	fup (i, 1, n)
		fup (j, 1, i)
			cnt += (a[i][j] == 1);
	write(cnt), lln;
	fup (i, 1, q)
	{
		int x = read(), y = read();
		if (a[x][y] == 1)
			puts("Parallel.");
		else if(!a[x][y])
			puts("Vertical.");
		else
			puts("No idea.");
	}
}
//functions

int main()
{
	init();
	return 0;
}
//main
