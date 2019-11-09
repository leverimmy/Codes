#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#define NO 3000005
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define mp(x, y) make_pair(x, y)
#define fup(i, x, y) for(register int i = x; i <= y; ++i)
#define lln putchar('\n')
#define blk putchar(' ')
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii;
ll read()
{
	ll ret = 0;
	char ch = ' ', last;
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ret = (ret << 3) + (ret << 1) + ch - '0', ch = getchar();
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

int n, f[NO], l[NO], ans;
bool ch[NO];
// variable

void init()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	n = read();
	string x;
	cin >> x;
	fup (i, 1, n)
		l[i] = i, ch[i] = x[i - 1] == '(' ? 0 : 1;
	fup (i, 2, n)
	{
		if (ch[i])
			if (!ch[l[i - 1] - (l[i - 1] != i - 1)] && l[i - 1] - (l[i - 1] != i - 1))
			{
				f[i] = 2 + f[i - 1], l[i] = l[i - 1] - (l[i - 1] != i - 1);
//				cout << l[i] - 1 << ',' << f[l[i] - 1] << endl;
				f[i] += f[l[i] - 1], l[i] = f[l[i] - 1] ? l[l[i] - 1] : l[i];
			}
//		fup (j, 1, i)
//			write(f[j]), putchar(','), write(l[j]), blk;
//		lln;
		ans = max(ans, f[i]);
	}
	int cnt = 0;
	fup (i, 1, n)
		cnt += (f[i] == ans);
	write(ans), blk, write(cnt), lln;
}
// functions

int main()
{
	init();
	return 0;
}
// main
