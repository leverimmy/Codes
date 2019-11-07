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

int n = 5, a[NO], book[6];
// variable

void dfs(int now)
{
	if (now == n + 1)
	{
		if (book[1] == 1 || book[1] == 2)
		{
			if (book[5] != 1)
				return;
		}
		else if (book[5] == 1)
			return;
		if (book[2] == 1 || book[2] == 2)
		{
			if (book[2] != 2)
				return;
		}
		else if (book[2] == 2)
			return;
		if (book[3] == 1 || book[3] == 2)
		{
			if (book[1] != 5)
				return;
		}
		else if (book[1] == 5)
			return;
		if (book[4] == 1 || book[4] == 2)
		{
			if (book[3] == 1)
				return;
		}
		else if (book[3] > 1)
			return;
		if (book[5] == 1 || book[5] == 2)
		{
			if (book[4] != 1)
				return;
		}
		else if (book[4] == 1)
			return;
		fup (i, 1, n)
			cout <<book[i] << ' ';
		cout <<endl;
		exit(0);
	}
	else
		fup (i, 1, n)
			if (!book[i])
				a[now] = i, book[i] = now, dfs(now + 1), book[i] = 0;
}
void init()
{
	freopen("14.in", "r", stdin);
	freopen("14.out", "w", stdout);
	dfs(1);
	
}
// function

int main()
{
	init();
	return 0;
}
// main
