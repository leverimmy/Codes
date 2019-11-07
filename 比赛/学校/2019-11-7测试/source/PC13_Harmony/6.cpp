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

int n;
string x, la; 
// variable

void init()
{
	freopen("6.in", "r", stdin);
	freopen("6.out", "w", stdout);
	x = 'A';
	n = read() - 1;
	fup (i, 1, n)
		la = x, x += 'A' + i, x += la;
	cout << x << endl;
}
// function

int main()
{
	init();
	return 0;
}
// main
