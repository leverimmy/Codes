#include <iostream>
#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <string> 
#include <queue>
#include <cmath>
#include <algorithm>
#define INF 0x3f3f3f3f
#define NO 100005
#define fi first
#define se second
#define lln putchar('\n')
#define blk putchar(' ')
#define fup(i, x, y) for(register int i = x; i <= y; ++i)
#define mp(x, y) make_pair(x, y)
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

int n, ne[NO];
string x, y;
// variable

void init()
{
	if (!(cin >> x))
		exit(0);
	cin >> y;
	int i = 0, j = -1;
	while (i < x.length())
		if (j == -1 || x[i] == x[j])
			ne[i] = j, i++, j++;
		else
			j = ne[j];
	i = 0, j = 0;
	while (i < x.length())
		if (j == -1 || x[i] == y[j])
		{
			i++, j++;
			if (j == y.length())
			{
				puts("YES");
				return;
			}
		}
		else
			j = ne[j];
	puts("NO");
}
//functions

int main()
{
	freopen("2.in", "r", stdin);
	freopen("2.out", "w", stdout);
	while (1)
		init();
	return 0;
}
//main
