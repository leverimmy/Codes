#pragma GCC optimize (2)
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <deque>
#define INF 0x3f3f3f3f
#define MO 200005
#define NO 100005
#define eps 1e-9
#define P 998244353ll
#define fup(i, x, y) for (register int i = x; i <= y; ++i)
#define fdn(i, x, y) for (register int i = x; i >= y; --i)
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
#define ls o << 1
#define  rs o << 1 | 1
#define lln putchar('\n')
#define blk putchar(' ')
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii;
inline ll read()
{
	char ch = ' ', last;
	ll ans = 0;
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ans = ans * 10 + int(ch - '0'), ch = getchar();
	if (last == '-')
		return -ans;
	return ans;
}
void write(ll x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x >= 10)
		write(x / 10);
	putchar(x % 10 + '0');
}
//head

int n;
db x, y, ans, k, T;
//variable

void init()
{
	freopen("artist.in", "r", stdin);
	freopen("artist.out", "w", stdout);
	n = read();
	fup (i, 1, n)
		scanf("%lf %lf", &x, &y), k = y / (x + y), ans += max(x * k, y * (1 - k));
	cin >> T;
	printf("%.2f\n", ans * T);
}
//functions

int main()
{
	init();
	return 0;
}
//main
