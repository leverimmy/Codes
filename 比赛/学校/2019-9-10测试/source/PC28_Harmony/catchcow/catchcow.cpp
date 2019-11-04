#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#define NO 10005
#define INF 0x3f3f3f3f
#define fi first
#define se second 
#define lln putchar('\n')
#define blk putchar(' ')
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii;
ll read()
{
	char ch = ' ', last;
	ll ret = 0;
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ret = (ret << 3) + (ret << 1) + ch - '0', ch = getchar();
	if (last == '-')
		return -ret;
	return ret;
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

ll n, k;
//variable

void init()
{
	freopen("catchcow.in", "r", stdin);
	freopen("catchcow.out", "w", stdout);
	n = read(), k = read();
	if (k <= n)
		write(n - k), lln, exit(0);
	db mid = (db)k / n;
	ll bb = 0, num = 1;
	while (num < mid)
		bb++, num <<= 1;
	num *= n;
	ll cur = num - k;
	if (bb && k - (num >> 1) <= cur)
		cur = k - (num >> 1), bb--;
	while (cur)
		bb += (cur % 2), cur /= 2;
	write(bb), lln;
}
//functions

int main()
{
	init();
	return 0;
}
//main
