#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
#define NO 105
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

ll ans, n;
// variable

void init()
{
	freopen("12.in", "r", stdin);
	freopen("12.out", "w", stdout);
	n = read(), ans = 1;
	fup (i, 2, sqrt(n))
		if (n % i == 0)
		{
			ll num = 1;
			while (n % i == 0)
				num++, n /= i;
			ans *= num;
		}
	if (n != 1)
		ans <<= 1;
	write(ans), putchar('\n');
}
// function

int main()
{
	init();
	return 0;
}
// main
