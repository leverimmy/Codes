#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#define NO 1000005
#define INF 0x3f3f3f3fll
#define P 998244353ull
#define MO 10005
#define mp(x, y) make_pair(x, y)
#define fi first
#define lln putchar('\n')
#define blk putchar(' ')
#define se second
#define fup(i, x, y) for (register int i = x; i <= y; ++i)
#define fdn(i, x, y) for (register int i = x; i >= y; --i)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
inline ll read()
{
    ll ret = 0;
    char ch = ' ', last;
    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9')
        ret = (((ret << 2) + ret) << 1) + ch - '0', ch = getchar();
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
// head

int n, m;
string x;
ull h[NO], mul[NO];
// variable

inline ull fast(ull x, ull y)
{
	ull ret = 1;
	while (y)
	{
		if (y & 1)
			ret = ret * x;
		x = x * x;
		y >>= 1;
	}
	return ret;
}
inline ull getval(int l, int r)
{
	return h[r] - h[l - 1] * mul[r - l + 1];
}
inline bool check(int a, int b, int l)
{
//	cout << a << ',' << b << ',' << l << ':' << getval(a, a + l - 1) << ' ' << getval(b, b + l - 1) << endl;
	return getval(a, a + l - 1) == getval(b, b + l - 1);
}
void init()
{
	freopen("lcp.in", "r", stdin);
	freopen("lcp.out", "w", stdout);
	n = read(), m = read();
	cin >> x;
	x += char(0), mul[0] = 1;
	fup (i, 1, n)
		h[i] = h[i - 1] * P + ull(x[i - 1]), mul[i] = mul[i - 1] * P;//, cout << h[i] << ' ';
//	lln;
//	cout << mul[1] << ',' << getval(2, 2)  << endl;
	while (m--)
	{
		int a = read(), b = read();
		if (a == b)
			puts("1");
		else
		{
			int len = min(n - a + 1, n - b + 1), l = 1, r = len;
			while (l <= r)
			{
				int mid = l + r >> 1;
				if (check(a, b, mid))
					l = mid + 1;
				else
					r = mid - 1;
			}
		//	cout << a << ',' <<b << ',' << l << ':' << x[a + l - 2] << ',' << x[b + l - 2] << endl;
			puts(x[a + l - 2] < x[b + l - 2] ? "0" : "1");
		}
	}
}
// function

int main()
{
	init();
	return 0;
}
// main
