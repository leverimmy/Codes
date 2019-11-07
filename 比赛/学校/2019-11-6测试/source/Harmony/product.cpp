#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#define NO 1000005
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

int n;
struct node
{
	ll t, d;
}a[NO];
// variable 

bool cmp(node i, node j)
{
	return i.d > j.d;
}
void init()
{
	n = read();
	fup (i, 1, n)
		a[i] = node{ read(), read() };
	sort(a + 1, a + n + 1, cmp);
	fup (i, 1, n)
		cout << a[i].t << ' ' << a[i].d << endl;
	lln;
	ll cur = 0, ans = 0;
	fup (i, 1, n)
		cur += a[i].t, ans += cur * a[i].d;
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
4
1 4
3 2
5 2
2 1
*/
