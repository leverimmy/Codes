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
#define MO 1000005
#define NO 200005
#define eps 1e-9
#define P 998244353ll
#define fup(i, x, y) for (int i = x; i <= y; i++)
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

int n, m, a[NO], k[NO], p[NO], f[NO];
bool ff;
//variable

void init()
{
	freopen("array.in", "r", stdin);
	freopen("array.out", "w", stdout);
	n = read();
	fup (i, 1, n)
		a[i] = read();
	if (n <= 1000)
	{
		m = read();
		fup (i, 1, m)
		{
			int p = read(), k = read(), ans = 0;
			while (p <= n)
				p += a[p] + k, ans++;
			write(ans), lln;
		}
		exit(0);
	}
	m = read(), ff = true;
	fup (i, 1, m)
		p[i] = read(), k[i] = read(), ff &= !k[i];
	if (ff)
	{
		fdn(i, n, 1)
			if (i + a[i] > n)
				f[i] = 1;
			else
				f[i] = 1 + f[i + a[i]];
		fup (i, 1, m)
			write(f[p[i]]), lln;
		exit(0);
	}
	fup (i, 1, m)
	{
		write((n - p[i] + 1) / (k[i] + 1)), lln;
	}
}
//functions

int main()
{
	init();
	return 0;
}
//main
/*
3
1 1 1
3
1 1
2 1
3 1
*/
