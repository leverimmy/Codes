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

ll a, b, p, c, d, f[NO], x, y;
// variable

void init()
{
	freopen("19.in", "r", stdin);
	freopen("19.out", "w", stdout);
	x = read(), y = read(), f[1] = f[2] = 1, a = read(), b = read(), c = read(), d = read(), p = a * b * c * d;
	fup (i, 3, x - 1)
		f[i] = (f[i - 1] + f[i - 2]) % p;
	fup (i, x, y)
	{
		if (i >= 3)
			f[i] = (f[i - 1] + f[i - 2]) % p;
		if (f[i] % a && f[i] % b  && f[i] % c && f[i] % d)
			write(i), putchar(' ');
	}
	putchar('\n');
}
// function

int main()
{
	init();
	return 0;
}
// main
