#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#define NO 305
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
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}
//head

int a[NO], p, n, s[NO * NO], ans, ss[NO * NO];
ll S;
vector<int> anss[NO];
bool book[100000000];
//variable

void dfs(int now, ll sum, int p)
{
	if (sum > S || p > n)
		return;
	if (now == n * (n - 1) / 2 + 1)
	{
		if (sum != S)
			return;
		ans++;
		for (int i = 1; i <= n; i++)
			anss[i].push_back(a[i]), write(a[i]), putchar(' ');
		putchar('\n');
		return;
	}
	bool f = false;
	for (int i = 1; i <= p && !f; i++)
		if (book[s[now] - a[i]] && s[now] != (a[i] << 1))
			f = true;
//	cout << s[now] << ',' << a[p] << ',' << f << endl;
	if (f)
		dfs(now + 1, sum, p);
	else
		for (int i = 1; i <= p; i++)
			if (s[now] - a[i] > a[p])
				book[s[now] - a[i]] = true, a[p + 1] = s[now] - a[i], dfs(now + 1, sum + s[now] - a[i], p + 1), book[s[now] - a[i]] = false;
}
//functions

int main()
{
	freopen("city.in", "r", stdin);
	freopen("city.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n * (n - 1) / 2; i++)
		s[i] = read(), S += s[i];
	S /= n - 1;
	sort(s + 1, s + n * (n - 1) / 2 + 1);
//	for (int i = 1; i <= n * (n - 1) / 2; i++)
//		cerr << s[i] << ' ';
//	cerr << endl;
	for (a[1] = 1; a[1] <= s[1] / 2; a[1]++)
		a[2] = s[1] - a[1], book[a[1]] = book[a[2]] = true, dfs(1, a[1] + a[2], 2), book[a[1]] = book[a[2]] = false;
	write(ans), putchar('\n');
	for (int i = 0; i < ans; i++)
	{
		for (int j = 1; j <= n; j++)
			write(anss[j][i]), putchar(' ');
		putchar('\n');
	}
	return 0;
} 
//main
/*
4
3 5 4 7 6 5

*/
