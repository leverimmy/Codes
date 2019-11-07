#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
#define NO 105
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
void write(ll x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}
// head

string x1;
int n;
// variable

void dfs(int x)
{
	if (x == n / 2 + 1 && n % 2)
	{
		putchar('\n');
		return;
	}
	if (x > n / 2)
		return;
	swap(x1[x - 1], x1[n - x]);
	cout << x1 << endl;
	dfs(x + 1);
}
void init()
{
	freopen("17.in", "r", stdin);
	freopen("17.out", "w", stdout);
	n = read();
	cin >> x1;
	dfs(1);
	cout << x1 <<endl;
}
// function

int main()
{
	init();
	return 0;
}
// main
