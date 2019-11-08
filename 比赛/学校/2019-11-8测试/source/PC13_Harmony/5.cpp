#include <iostream>
#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <string> 
#include <queue>
#include <cmath>
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

int n, m, f[NO], ans;
struct E
{
	int u, v, c;
} e[MO];
// variable

int getf(int o)
{
	return  o == f[o] ? o : f[o] = getf(f[o]);
}
bool cmp(E i, E j)
{
	return i.c < j.c;
}
void init()
{
	if (scanf("%lld", &n) == -1)
		exit(0);
	m = read(), ans = 0;
	fup (i, 1, m)
		e[i] = E{ read(), read(), read() };
	fup (i, 1, n)
		f[i] = i;
	sort(e + 1, e + m + 1, cmp);
	fup (i, 1, m)
		if (getf(e[i].u) != getf(e[i].v))
			f[getf(e[i].u)] = getf(e[i].v), ans += e[i].c;
	write(ans), lln;
}
//functions

int main()
{
	freopen("5.in", "r", stdin);
	freopen("5.out", "w", stdout);
	while (1)
		init();
	return 0;
}
//main
