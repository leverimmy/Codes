#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 0x3f3f3f3fll
#define NO 20000005
#define MO 2000005
#define ls o << 1
#define rs o << 1 | 1
using namespace std;
typedef unsigned long long ll;
typedef double db;
typedef pair<int, pair<int, int> > pii;
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

ll a[NO], cnt;
//variable

void init()
{
	freopen("prd.in", "r", stdin);
	freopen("prd.out", "w", stdout);
	a[1] = 4, a[2] = 7, cnt = 2;
	int be = 1, ed = cnt;
	for (int i = 1; i <= 11; i++)
	{
		for (int j = be; j <= ed; j++)
			a[++cnt] = a[j] * 10 + 4, a[++cnt] = a[j] * 10 + 7;
		be = ed + 1, ed = cnt;
	}
	be = 1, ed = cnt;
	ll ed11 = cnt;
	for (int k = 1; k <= 20; k++)
	{
		for (int i = 1; i <= ed11; ++i)
		{
			for (int j = be; j <= ed && a[j] * a[i] <= 1e13; ++j)
				a[++cnt] = a[i] * a[j];
		}
		be = ed + 1, ed = cnt;
	}
	sort(a + 1, a + cnt + 1);
	cnt = unique(a + 1, a + cnt + 1) - a - 1;
//	for (int i = 1; i <= 15; i++)
//		cout << a[i] << ' ';
//	cout << endl;
	int T = read();
	while (T--)
	{
		ll A = read(), B = read();
		write(upper_bound(a + 1, a + cnt + 1, B) - upper_bound(a + 1, a + cnt + 1, A - 1)), putchar('\n');
	}
}
//functions

int main()
{
	init();
	return 0;
}
//main
