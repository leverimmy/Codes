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

ll n, m, r;
// variable

void init()
{
	freopen("9.in", "r", stdin);
	freopen("9.out", "w", stdout);
	m = read(), n = read(), r = read();
	if (!r)
		r += n;
	ll ans = r, cnt = 0;
	while (ans <= m)
		if (cnt == 9 || ans + n > m)
			cnt = 0, write(ans), putchar('\n'), ans += n;
		else
			cnt++, write(ans), putchar(','), ans += n;
}
// function

int main()
{
	init();
	return 0;
}
// main
