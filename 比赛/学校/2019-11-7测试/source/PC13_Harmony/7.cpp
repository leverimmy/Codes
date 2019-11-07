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
// head

int n, ans;
bool book[NO], a[NO][NO]; 
// variable

void dfs(int now, int num)
{
	if (num + n - now < n / 2)
		return;
	if (now == n + 1)
	{
		if (num <= n / 2)
			return;
		fup (i, 1, n)
			if (book[i])
				fup (j, 1, n)
					if (book[j] != a[i][j])
						return;
		fup (i, 1, n)
			if (book[i])
				cout << i << ' ';
		cout << endl, exit(0);
	}
	book[now] = 1, dfs(now + 1, num + 1), book[now] = 0, dfs(now + 1, num);
}
void init()
{
	freopen("7.in", "r", stdin);
	freopen("7.out", "w", stdout);
	n = read();
	fup (i, 1, n)
		fup (j, 1, n)
			a[i][j] = read();
	dfs(1, 0);
}
// function

int main()
{
	init();
	return 0;
}
// main
/*
3
1 0 1
0 1 0
1 0 1
*/ 
