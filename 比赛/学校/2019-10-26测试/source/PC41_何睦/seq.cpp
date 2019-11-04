#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#define NO 100005
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii;
inline ll read()
{
	ll ret = 0;
	char ch = ' ', last;
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ret = (ret <<3) + (ret <<1) + ch  - '0', ch = getchar();
	return (last == '-') ? -ret : ret;
}
void write(ll x)
{
	if (x < '0')
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}
//head

ll a, b, ans;
//variable

ll gcd(ll x, ll y)
{
	if (x < y)
		swap(x, y);
	if (y)
		ans += x / y;
	return !y ? x : gcd(y, x % y);
}
//functions

int main()
{
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	a = read(), b = read(), gcd(a, b);
	cout << ans + 1 << endl;
	return 0;
} 
//main
/*
a[0]
a[1]
|a[0] - a[1]|
||a[0] - a[1]| - a[1]|

*/
