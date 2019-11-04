#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
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

ll a[3], cnt;
map<ll, bool> m;
//variable

//functions

int main()
{
	freopen("seq.in", "r", stdin);
	freopen("seq.ans", "w", stdout);
	a[0] = read(), a[1] = read(), cnt += !m[a[0]], m[a[0]] = true, cnt += !m[a[1]], m[a[1]] = true;
	while (a[1])
		a[2] = abs(a[1] - a[0]), cnt += !m[a[2]], m[a[2]] = true, a[0] = a[1], a[1] = a[2];//, cout << a[0] << ',' << a[1] << endl;
	cout << cnt << endl;
	return 0;
} 
//main
