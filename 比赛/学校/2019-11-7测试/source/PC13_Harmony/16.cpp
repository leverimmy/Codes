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

int n, s, a[NO][NO];
// variable

void init()
{
	freopen("16.in", "r", stdin);
	freopen("16.out", "w", stdout);
	n = read(), s = read();
	fup (i, 1, s - 1)
		a[1][i] = n++;
	fup (i, 1, s - 1)
		a[i][s] = n++;
	for (int i = s; i >= 2; i--)
		a[s][i] = n++;
	for (int i = s; i >= 2; i--)
		a[i][1] = n++;
	fup (i, 1, s)
	{
		fup (j, 1, s)
			if (!a[j][i])
				putchar(' '), putchar(' '), putchar(' ');
			else
				write(a[j][i]), putchar(' ');
		putchar('\n');
	}
}
// function

int main()
{
	init();
	return 0;
}
// main
