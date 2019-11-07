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


// variable

void init()
{
	freopen("11.in", "r", stdin);
	freopen("11.out", "w", stdout);
	db n;
	cin >> n;
	if (!n)
		exit(0);
	db k = 1.0, ans = 0;
	int ret = 0;
	while ((k += 1.0) && (ans + (1 / k) <= n))
		ans += 1 / k, ret++;
	write(ret + (ans < n)), putchar(' '), puts("card(s)");
}
// function

int main()
{
	while (1)
		init();
	return 0;
}
// main
