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
	if (x > '9')
		write(x / 10);
	putchar(x % 10 + '0');
}
// head

ll n, m, a;
// variable

void init()
{
	freopen("8.in", "r", stdin);
	freopen("8.out", "w", stdout);
	n = read(), m = read(), a = read();
	ll x = 0, y = 1;
	while (++x)
	{
		if (x * n + y * m > a)
			break;
		while (y)
		{
			if (x * n + y * m > a)
				break;
			write(x), putchar(','), write(y), putchar('\n');
			y++;
		}
		y = x + 1;
	}
}
// function

int main()
{
	init();
	return 0;
}
// main
/*
3
1 0 1
0 1 0
1 0 1
*/ 
