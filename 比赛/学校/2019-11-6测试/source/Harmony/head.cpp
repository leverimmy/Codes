#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#define NO 405
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

// variable 

void init()
{
	
}
// functions

int main()
{
	init();
	return 0;
}
// main
