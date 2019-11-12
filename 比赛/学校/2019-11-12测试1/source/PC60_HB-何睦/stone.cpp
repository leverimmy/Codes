#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#define NO 4000005
#define LENO 15
#define INF 0x3f3f3f3f
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
#define fup(i, x, y) for (register int i = x; i <= y; ++i)
#define fdn(i, x, y) for (register int i = x; i >= y; --i)
#define lln putchar('\n')
#define blk putchar(' ')
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
ll read()
{
	ll ret = 0;
	char ch = ' ', last;
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ret = ((ret + (ret << 2)) << 1) + (ch ^ '0'), ch = getchar();
	return last == '-' ? -ret : ret;
}
void write(ll x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}
//head

const int base = 100000000;
ll n;
struct INT
{
	int a[LENO], h;
	void init(int x)
	{
		memset(a, 0, sizeof(a));
		h = 1, a[1] = x;
	}
	INT operator +(INT y)
	{
		register INT ret;
		ret.init(0);
		ret.h = max(h, y.h) + 1;
		fup (i, 1, ret.h - 1)
			ret.a[i + 1] = (ret.a[i] + (ll)a[i] + y.a[i]) / base, ret.a[i] = (ret.a[i] + (ll)a[i] + y.a[i]) % base;
		while (!ret.a[ret.h])
			ret.h--;
		return ret;
	}
	INT operator *(int y)
	{
		register INT ret;
		ret.init(0);
		fup (i, 1, h)
			ret.a[i + 1] = (ret.a[i] + (ll)a[i] * y) / base, ret.a[i] = (ret.a[i] + (ll)a[i] * y) % base;
		while (ret.a[ret.h])
			ret.h++;
		ret.h--;
		return ret;
	}
	void print()
	{
		fdn (i, h, 1)
			if (i == h)
				write(a[i]);
			else
			{
				int k = base / 10;
				while (k)
					putchar((a[i] / k) % 10 + '0'), k /= 10;
			}
	}
};
//variable

void init()
{
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	n = read();
	register int y;
	register INT x, ans, yy;
	x.init(0), ans.init(0);
	fup (i, 1, n)
	{
		y = read();
		ans = ans + x * y;
		yy.init(y);
		x = x + yy;
	}
	ans.print(), lln;
}
//functions

int main()
{
	init();
	return 0;
}
//main
