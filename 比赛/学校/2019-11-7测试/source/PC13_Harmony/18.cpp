#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
#define NO 100005
#define fup(i, x, y) for(int i = x; i <= y; ++i)
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii; 
ll read()
{
	ll ans = 0;
	char ch = ' ', last;
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ans = (ans << 3) + (ans << 1) + ch - '0', ch = getchar();
	return last == '-' ? -ans : ans; 
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

int n, f[NO], m;
bool book[NO];
// variable

int getf(int o)
{
	return o == f[o] ? o : f[o] = getf(f[o]);
}
void init()
{
	freopen("18.in", "r", stdin);
	freopen("18.out", "w", stdout);
	n = read(), m = read();
	fup (i, 1, n)
		f[i] = i;
	fup (i, 1, m)
	{
		int x = read(), y = read();
		f[getf(x)] = getf(y);
	}
	int ans = 0;
	fup (i, 1, n)
		ans += !book[getf(i)], book[getf(i)] = true;
	write(ans), putchar('\n');
}
// function

int main()
{
	init();
	return 0;
}
// main
