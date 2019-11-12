#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#define NO 1000005
#define INF 0x3f3f3f3f
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
#define fup(i, x, y) for (register int i = x; i <= y; ++i)
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

int n, T;
ll ans;
bool c[NO];
//variable

void work()
{
	ll l = 1, r = n, cur = 0;
	while (c[l] && l <= n)
		l++;
	while (c[r] && r)
		r--;
//	cout << l << ',' << r << ':';
	if (l > r)
	{
		ans = 0;
		return;
	}
	int len = 0, lp = 0, l1 = l, r1 = r;
	fup (i, l, r)
		if (c[i])
		{
			if (!len)
				lp = i;
			len++;
		}
		else
		{
			if (len)
			{
//				cout << lp << ',' << i - 1 << ',' << len << endl;
				if (lp - l1 > r1 - i + 1)
					cur += len * (r1 - i + 1), r1 -= len;
				else
					cur += len * (lp - l1), l1 += len;
				len = 0;
			}
		}
//	cout << cur << endl;
	ans = min(ans, cur);
}
void init()
{
	ans = INF, n = 0;
	char ch = getchar();
	while (ch != '\n')
		c[++n] = (ch == 'R'), ch = getchar();
	n--;
	work();
	fup (i, 1, n)
		c[i] ^= 1;
	work(), write(ans), lln;
}
//functions

int main()
{
	freopen("sushi.in", "r", stdin);
	freopen("sushi.out", "w", stdout);
	T = read(), getchar();
	while (T--)
		init();
	return 0;
}
//main
