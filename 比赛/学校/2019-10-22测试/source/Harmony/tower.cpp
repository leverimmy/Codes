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
#define NO 2000005
#define eps 1e-9
#define P 998244353ll
#define fup(i, x, y) for (register int i = x; i <= y; ++i)
#define fdn(i, x, y) for (register int i = x; i >= y; --i)
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
#define ls o << 1
#define  rs o << 1 | 1
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

ll n, x[NO], y[NO], f[NO], cnt, ans;
struct ed
{
	ll u, v, c;
}edge[NO];
//variable

bool cmp(ed i, ed j)
{
	return i.c < j.c;
}
int getf(int o)
{
	return f[o] == o ? o : f[o] = getf(f[o]);
}
void init()
{
    freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);
    n = read();
	fup (i, 1, n)
		x[i] = read(), y[i] = read(), f[i] = i;
	fup (i, 1, n)
		fup (j, 1, i - 1)
			edge[++cnt] = ed{ i, j, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) };
	sort(edge + 1, edge + cnt + 1, cmp);
	fup (i, 1, cnt)
		if (getf(edge[i].u) != getf(edge[i].v))
			f[getf(edge[i].u)] = getf(edge[i].v), ans = max(ans, edge[i].c);
	write(ans), lln;
}
//functions

int main()
{
	init();
	return 0;
}
//main
/*
4
1 3
5 4
7 2
6 1
*/