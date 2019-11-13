#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 0x3f3f3f3fll
#define NO 800005
using namespace std;
typedef long long ll;
typedef double db;
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

int n, m, ans, l[NO];
struct node
{
	int l, r;
}a[NO];
//variable

bool cmp(node i, node j)
{
	return i.r < j.r;
}
void init()
{
	freopen("clean.in", "r", stdin);
	freopen("clean.out", "w", stdout);
	m = read(), n = read();
	for (int i = 1; i <= n; ++i)
		a[i].l = read(), a[i].r = read();
	sort(a + 1, a + n + 1, cmp);
	int cur = 0, r = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (a[i].l > r)
			l[r] = cur, cur = a[i].l;
		r = a[i].r, cur = min(cur, a[i].l);
	}
	l[r] = cur;
	for (int i = m; i >= 1; --i)
		if (!l[i])
			ans++;
		else
			i = l[i];
	write(ans), putchar('\n');
}
//functions

int main()
{
	init();
	return 0;
}
//main
