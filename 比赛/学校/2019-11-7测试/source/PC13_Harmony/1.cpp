#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
#define NO 10005
#define for(i, x, y) for(int i = x; i <= y; ++i)
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

int n, m;
// variable

void init()
{
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	n = read(), m = read();
	n = n / m + (n % m != 0);
	int ans = 0;
	while (n--)
		ans = ((ans << 1) | 1);
	cout << ans << endl;
}
// function

int main()
{
	init();
	return 0;
}
// main
