#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#define NO 10005
#define INF 0x3f3f3f3f
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
#define fup(i, x, y) for (register int i = x; i <= y; ++i)
#define lln putchar('\n')
#define blk putchar(' ')
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
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

int n, a[NO];
//variable

void init()
{
	freopen("attack.in", "r", stdin);
	freopen("attack.out", "w", stdout);
	srand(20040708ull);
	ll s = 0;
	n = read();
	fup (i, 1, n)
		a[i] = read();
	fup (i, 1, n)
		if (rand() % 2)
			s += a[i];
	write(s), lln;
}
//functions

int main()
{
	init();
	return 0;
}
//main
