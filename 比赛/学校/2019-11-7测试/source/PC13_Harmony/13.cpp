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

ll ans, n, p[NO], num[NO], cnt, n1;
// variable

void init()
{
	freopen("13.in", "r", stdin);
	freopen("13.out", "w", stdout);
	n1 = n = read(), ans = 1;
	fup (i, 2, sqrt(n))
		if (n % i == 0)
		{
			p[++cnt] = i;
			while (n % i == 0)
				num[cnt]++, n /= i;
		}
	if (n != 1)
		p[++cnt] = n, num[cnt] = 1;
	write(n1), putchar('=');
	fup (i, 1, cnt)
	{
		write(p[i]);
		if (num[i] > 1)
			putchar('^'), write(num[i]);
		if (i < cnt)
			putchar('*');
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
