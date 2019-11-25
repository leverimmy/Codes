#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
#define NO 5005
#define INF 0x3f3f3f3fll
#define lln putchar('\n')
#define blk putchar(' ')
typedef long long ll;
typedef double db;
using namespace std;
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
// head

int n, f[NO][NO], a[NO], ans[NO];
string x;
// variable

void init()
{
	freopen("palindrome.in", "r", stdin);
	freopen("palindrome.out", "w", stdout);
	cin >> x, n = x.length();
	for (int i = 1; i <= n; i++)
		a[i] = x[i - 1], f[i][i] = 1;
	ans[1] = n;
	for (register int i = 1; i <= n - 1; ++i)
	{
		register int l = i - 1, r = i + 1;
		while (l >= 1 && r <= n)
		{
			if (a[l] != a[r])
				break;
			f[l][r] = f[l][i - 1] + 1, ans[f[l][r]]++;
			l--, r++;
		}
		l = i, r = i + 1;
		while (l >= 1 && r <= n)
		{
			if (a[l] != a[r])
				break;
			f[l][r] = f[l][i - 1] + 1, ans[f[l][r]]++;
			l--, r++;
		}
	}
	for (int i = n; i >= 1; i--)
		ans[i] += ans[i + 1];
	for (int i = 1; i <= n; i++)
		write(ans[i]), blk;
	lln;
}
// functions

int main()
{
	init();
	return 0;
}
// main
