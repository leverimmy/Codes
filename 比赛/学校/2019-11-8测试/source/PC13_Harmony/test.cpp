#include <iostream>
#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <string> 
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
#define NO 10005
#define MO 100005
#define fi first
#define se second
#define lln putchar('\n')
#define blk putchar(' ')
#define fup(i, x, y) for(register int i = x; i <= y; ++i)
#define mp(x, y) make_pair(x, y)
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

int n, d[NO], c[NO], ans[NO], cnt;
pii p[NO];
// variable

void add(int p, int x)
{
	for (int i = p; i <= n; i += (i & (-i)))
		d[i] += x;
}
int ask(int p)
{
	int ret = 0;
	for (int i = p; i; i -= (i & -i))
		ret += d[i];
	return ret;
}
void init()
{
	if (scanf("%lld", &n) == -1)
		exit(0);
	fup (i, 1, n)
		p[i] = mp(read(), read()), c[i] = p[i].se, swap(p[i].fi, p[i].se);
	sort(p + 1, p + n + 1);
	sort(c + 1, c + n + 1);
	cnt = unique(c + 1, c + n + 1) - c - 1;
	fup (i, 1, n)
		p[i].se = lower_bound(c + 1, c + n + 1, p[i].se) - c;
	fup (i, 1, n)
		ans[ask(p[i].se)]++, add(p[i].fi, 1);
	fup (i, 0, n - 1)
		write(ans[i]), lln;
}
//functions

int main()
{
//	freopen("16.in", "r", stdin);
//	freopen("16.out", "w", stdout);
	while (1)
		init();
	return 0;
}
//main
