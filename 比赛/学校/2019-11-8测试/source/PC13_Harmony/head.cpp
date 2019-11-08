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

int n, c[NO], cnt, MAX[NO];
struct edge
{
	int h, l, r;
}e[NO];
// variable

void init()
{
	if (scanf("%lld", &n) == -1)
		exit(0);
	fup (i, 1, n)
	{
		int k = read(), x = read(), y = read();
		fup (j, 3, k)
		{
			int x = read();
			if ()
		}
	}
}
//functions

int main()
{
//	freopen("18.in", "r", stdin);
//	freopen("18.out", "w", stdout);
	while (1)
		init();
	return 0;
}
//main
