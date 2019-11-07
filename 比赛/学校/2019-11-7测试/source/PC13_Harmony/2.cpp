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

int n, book[NO];
string x, y[NO];
// variable

void init()
{
	freopen("2.in", "r", stdin);
	freopen("2.out", "w", stdout);
	n = read();
	fup (i, 1, n)
		cin >> y[i];
	fup (i, 0, y[1].size() - 1)
	{
		memset(book, 0, sizeof(book));
		int MAX = 0, ch;
		fup (j, 1, n)
		{
			book[y[j][i]]++;
			if (book[y[j][i]] > MAX)
				MAX = book[y[j][i]], ch = y[j][i];
			else if(book[y[j][i]] == MAX)
				ch = min(ch, (int)y[j][i]);
		}
		x += char(ch);
	}
	cout << x << endl;
}
// function

int main()
{
	init();
	return 0;
}
// main
