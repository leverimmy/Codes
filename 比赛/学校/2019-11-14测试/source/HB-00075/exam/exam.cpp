#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
#define NO 3000005
#define INF 0x3f3f3f3fll
#define lln putchar('\n')
#define blk putchar(' ')
typedef long long ll;
typedef double db;
using namespace std;
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
// head

int n, a[NO], b[NO], f[NO], c[NO], cnt, ans, Max[NO];
bool cir[NO], book[NO];
// variable

int getf(int o)
{
	return f[o] == o ? o : f[o] = getf(f[o]);
}
void init()
{
	freopen("exam.in", "r", stdin);
	freopen("exam.out", "w", stdout);
	n = read();
	for (register int i = 1; i <= n; ++i)
		a[i] = read(), b[i] = read(), c[++cnt] = a[i], c[++cnt] = b[i];
	sort(c + 1, c + cnt + 1);
	cnt = unique(c + 1, c + cnt + 1) - c - 1;
	for (register int i = 1; i <= cnt; ++i)
		f[i] = i, cir[i] = false, Max[i] = i;
	for (register int i = 1; i <= n; ++i)
	{
		a[i] = lower_bound(c + 1, c + cnt + 1, a[i]) - c, b[i] = lower_bound(c + 1, c + cnt + 1, b[i]) - c;
//		cout << a[i] << ' ' << b[i] << endl;
		if (getf(a[i]) == getf(b[i]))
		{
			if (cir[getf(a[i])])
				puts("-1"), exit(0);
			cir[getf(a[i])] = true;
			continue;
		}
		cir[getf(a[i])] |= cir[getf(b[i])];
		Max[getf(a[i])] = max(Max[getf(a[i])], Max[getf(b[i])]);
		f[getf(b[i])] = getf(a[i]);
	}
	for (register int i = 1; i <= cnt; ++i)
	{
		if (cir[getf(i)])
			ans = max(ans, c[i]);
		else if (Max[getf(i)] != i)
			ans = max(ans, c[i]);
//		cout << f[i] << ',' << cir[i] << ',' << Max[i] << endl;
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
