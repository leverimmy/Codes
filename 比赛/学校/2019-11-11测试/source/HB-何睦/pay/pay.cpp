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
#define NO 505
#define MO 300005
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
#define fup(i, x, y) for(register int i = x; i <= y; ++i)
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

ll n, m, f[NO], g, d, ans;
struct E
{
	ll u, v, g, d;
}e[MO], e1[MO];
//variable

bool cmp(E i, E j)
{
	return i.d < j.d;
}
bool cmp2(E i, E j)
{
	return i.g == j.g ? i.d > j.d : i.g < j.g;
}
ll getf(ll o)
{
	return f[o] == o ? o : getf(f[o]);
}
inline bool check(register ll G)
{
	register ll tot = 0, cnt = 0, cur = e[G].g * g, k = 0;
	fup (i, 1, n)
		f[i] = i;
	fup (i, 1, m)
		if (e[i].g <= e[G].g)
			e1[++cnt] = e[i];
	sort(e1 + 1, e1 + cnt + 1, cmp);
	fup (i, 1, cnt)
		if (getf(e1[i].u) != getf(e1[i].v))
			tot++, k = max(k, e1[i].d), f[getf(e1[i].v)] = getf(e1[i].u);
	cur += k * d;
	if (tot == n - 1)
		ans = min(ans, cur);
	return tot == n - 1;
}
inline ll check2(register ll G)
{
	register ll tot = 0, cnt = 0, cur = e[G].g * g, k = 0;
	fup (i, 1, n)
		f[i] = i;
	fup (i, 1, m)
		if (e[i].g <= e[G].g)
			e1[++cnt] = e[i];
	sort(e1 + 1, e1 + cnt + 1, cmp);
	fup (i, 1, cnt)
		if (getf(e1[i].u) != getf(e1[i].v))
			tot++, k = max(k, e1[i].d), f[getf(e1[i].v)] = getf(e1[i].u);
	cur += k * d;
	return cur;
}
void init()
{
	freopen("pay.in", "r", stdin);
	freopen("pay.out", "w", stdout);
	n = read(), m = read(), g = read(), d = read(), ans = INF * INF;
	fup (i, 1, m)
		e[i] = E{ read(), read(), read(), read() };
	sort(e + 1, e + m + 1, cmp2);
	ll l = 1, r = m;
	while (l < r)
	{
		ll mid = l + r >> 1;
		if (check(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	r = m;
	if (l > r)
		puts("-1"), exit(0);
	fup (k, l, r)
		ans = max(ans, check2(k));
	write(ans), lln;
}
//functions

int main()
{
	init();
	return 0;
}
//main

