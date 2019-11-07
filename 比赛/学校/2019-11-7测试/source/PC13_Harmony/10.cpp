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
	freopen("10.in", "r", stdin);
	freopen("10.out", "w", stdout);
	m = read(), n = read();
	ll ans = m, cnt = 0, num = 0, base = 0;
	while (ans <= n)
		if (cnt == 4 || ans + 1 > n)
			write(num ? (min(n + 1, base + 5) - cnt - 1) : ans), cnt = 0, putchar('\n'), ans++, num ^= 1;
		else
			base = (!cnt ? ans : base), cnt++, write(num ? (min(n + 1, base + 5) - cnt) : ans), putchar(' '), ans++;
}
// function

int main()
{
	init();
	return 0;
}
// main
