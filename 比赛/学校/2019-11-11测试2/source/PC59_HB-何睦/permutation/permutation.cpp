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

int n, a[NO], d[NO], ans[NO], book[NO], cnt, la[NO], s, ne[NO];
//variable

void init()
{
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
	n = read();
	fup (i, 1, n)
		a[i] = read(), book[a[i]]++;
	int cur = 0;
	fdn (i, n, 1)
	{
		if (book[i] < cur)
			puts("-1"), exit(0);
		d[i] = book[i] - cur, cur = book[i], cnt += d[i];
	}
	write(cur), lln;
	memset(book, 0, sizeof(book));
	fup (i, 1, n + 1)
		ne[i - 1] = i, la[i] = i - 1;
	int cnt = 0;
	while (ne[0] != n + 1)
	{
		int u = ne[0], tot = 0;
		cnt++;
		while (u != n + 1)
		{
			tot++;
			while (book[a[u]] == cnt)
				u = ne[u];
			if (u > n)
				break;
			book[a[u]] = cnt, ans[u] = cnt, ne[la[u]] = ne[u], la[ne[u]] = la[u];
		}
//		cout << tot << endl;
//		fup (i, 0, n)
//			cout << ans[i] << ',' << la[i] << ',' << ne[i] << endl;
//		lln;
	}
	fup (i, 1, n)
		write(ans[i]), blk;
	lln;
}
//functions

int main()
{
	init();
	return 0;
}
// main

