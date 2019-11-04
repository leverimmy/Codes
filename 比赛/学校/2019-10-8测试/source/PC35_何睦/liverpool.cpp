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
#define NO 2000005
#define eps 1e-9
#define P 998244353ll
#define fup(i, x, y) for (register int i = x; i <= y; ++i)
#define fdn(i, x, y) for (register int i = x; i >= y; --i)
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
#define ls o << 1
#define  rs o << 1 | 1
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

int rt, n, m, p[NO][26], cnt;
ll v[NO], ans, s, cur;
string x;
//variable

inline void insert(string x, ll val)
{
	int now = rt, l = x.length() - 1;
	fup (i, 0, l)
	{
		if (!p[now][x[i] - 'a'])
			p[now][x[i] - 'a'] = ++cnt;
		now = p[now][x[i] - 'a'];
	}
	v[now] = val;
}
inline int ask(string x)
{
	int now = rt, l = x.length() - 1;
	fup (i, 0, l)
		now = p[now][x[i] - 'a'];
	return v[now];
}
void init()
{
	freopen("liverpool.in", "r", stdin);
	freopen("liverpool.out", "w", stdout);
	memset(v, -1, sizeof(v));
	n = read();
	fup (i, 1, n)
		cin >> x, insert(x, read());
	m = read();
	fup (i, 1, m)
	{
		ans = 0, s = read(), cur = 0;
		fup (i, 1, s)
		{
			cin >> x, cur = ask(x);
			if (~cur)
				ans += cur;
			else
			{
				ans = -1;
				break;
			}
		}
		write(ans), lln;
	}
}
//functions

int main()
{
	init();
	return 0;
}
//main
/*
2 
a 10
b 20 
3 
2 a b 
1 b 
2 a c
*/
