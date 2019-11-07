#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
#define NO 1005
#define fup(i, x, y) for(int i = x; i <= y; ++i)
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii; 
ll read()
{
	ll ans = 0;
	char ch = ' ', last;
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ans = (ans << 3) + (ans << 1) + ch - '0', ch = getchar();
	return last == '-' ? -ans : ans; 
}
// head

// variable

bool ip(ll x)
{
	if (x == 1)
		return false;
	if (x == 2)
		return true;
	if (x % 2 == 0)
		return false;
	for (ll i = 3; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}
void init()
{
	freopen("5.in", "r", stdin);
	freopen("5.out", "w", stdout);
	ll x = read();
	for (ll i = x + 1; ; i++)
		if (ip(i))
			cout << i << endl, exit(0);
}
// function

int main()
{
	init();
	return 0;
}
// main
