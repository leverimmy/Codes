#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>
#include <ctime>
#define INF 0x3f3f3f3fll
#define NO 5005
#define MO 300005
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
#define fup(i, x, y) for(register int i = x; i <= y; ++i)
#define fdn(i, x, y) for(register int i = x; i >= y; --i)
#define lln putchar('\n')
#define blk putchar(' ')
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
ll read()
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

int n, m, a[NO][NO], book[NO];
string x;
//variable

void init()
{
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	n = read(), m = read();
	fup (i, 1, n)
		fup (j, 1, m)
		{
			char ch = getchar();
			while (ch == ' ' || ch == '\n' || ch == '\r')
				ch = getchar();
			a[i][j] = ch - '0', a[i][j] = (a[i][j] ? a[i][j - 1] + 1 : 0);
		}
	int ans = 0;
	fup (i, 1, m)
	{
		memset(book, 0, sizeof(int) * (m + 1));
		fup (j, 1, n)
			book[a[j][i]]++;
		fdn (j, m, 1)
			book[j] += book[j + 1];
		fup (j, 1, m)
			ans = max(ans, book[j] * j);
	}
	write(ans), lln;
}
//functions

int main()
{
	init();
	return 0;
}
//main

