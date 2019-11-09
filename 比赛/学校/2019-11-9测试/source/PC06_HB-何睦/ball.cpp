#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 0x3f3f3f3f
#define NO 200005
#define lln putchar('\n')
#define blk putchar(' ')
#define fi first 
#define se second
#define mp(x, y) make_pair(x, y)
#define eps 1e-6
#define fup(i, x, y) for (register int i = x; i <= y; i++)
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii;
inline ll read()
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
db ans[NO];
struct node
{
	int x, r, p;
}c[NO];
// variable

bool cmp(node i, node j)
{
	return i.x < j.x;
}
/*
inline bool check(int i, int j, db x)
{
	register db r = ans[c[j].p];
	return 4 * x * r <= ll(c[i].x - c[j].x) * (c[i].x - c[j].x);
}
inline db cal(int i, int j)
{
	register db l = 0, r = c[i].r, mid;
	while (l < r + eps)
		mid = (l + r) / 2, (check(i, j, mid) ? (l = mid + eps) : (r = mid - eps));
	return l;
}
*/
void init()
{
	n = read();
	fup (i, 1, n)
		c[i] = node{read(), read(), i };
	sort(c + 1, c + n + 1, cmp);
	fup (i, 1, n)
	{
		db h = c[i].r;
		fup (j, 1, i - 1)
			h = min(h, ((c[i].x - c[j].x) * ll(c[i].x - c[j].x) / (4.000000000 * ans[c[j].p])));
		ans[c[i].p] = h;
	}
	fup (i, 1, n)
		printf("%.3f\n", ans[i]);
}
// functions

int main()
{	
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	init();
	return 0;
}
// main
/*
3
0 9
8 1
13 7

*/
