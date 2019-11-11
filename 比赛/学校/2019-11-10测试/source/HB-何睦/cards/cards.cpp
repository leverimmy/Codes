#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
#define NO 100005
#define MO 1000005
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
#define fup(i, x, y) for(register int i = x; i <= y; ++i)
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

int n, m;
ll ans;
string x;
//variable

void init()
{
	freopen("cards.in", "r", stdin);
	freopen("cards.out", "w", stdout);
	n = read(), m = read();
	if (n < m)
	{
		ll len = m / (n + 1), cur = len;
		while (cur--)
			x += 'x';
		ans -= len * len;
		fup (i, 1, n)
		{
			x += 'o', ans++;
			cur = min(m - len * (i), len), ans += cur * cur;
			while (len)
				x += 'x';
		}
		write(ans), lln;
		cout << x << endl;
	}
	else if (n == m)
	{
		puts("0");
		fup (i, 1, n)
			putchar('o'), putchar('x');
		lln;
	}
	else
	{
		ans = (ll)n * n - (ll)m * m;
		while (n--)
			putchar('o');
		while (m--)
			putchar('x');
	}
}
//function

int main()
{
	init();
	return 0;
}
//main
