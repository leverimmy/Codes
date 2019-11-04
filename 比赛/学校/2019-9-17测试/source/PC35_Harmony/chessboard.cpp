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
#define NO 205
#define eps 1e-9
#define P 998244353ll
#define fup(i, x, y) for (int i = x; i <= y; i++)
#define fdn(i, x, y) for (int i = x; i >= y; i--)
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
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

int n, match[NO];
bool book[NO], a[NO][NO];
//variable

bool dfs(int now)
{
	fup (i, 1, n)
		if (!book[i] && a[now][i])
		{
			book[i] = true;
			if (!match[i] || dfs(match[i]))
			{
				match[i] = now;
				return true;
			}
		}
	return false;
}
void init()
{
	freopen("chessboard.in", "r", stdin);
	freopen("chessboard.out", "w", stdout);
	n = read();
	fup (i, 1, n)
	{
		string x;
		cin >> x;
		fup (j, 0, n - 1)
			if (x[j] == '.')
				a[i][j + 1] = true;
	}
	int ans = 0;
	fup (i, 1, n)
		memset(book, false, sizeof(book)), ans += dfs(i);
	write(ans), lln;
}
//functions

int main()
{
	init();
	return 0;
}
//main

