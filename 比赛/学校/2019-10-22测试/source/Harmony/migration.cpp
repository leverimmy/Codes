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

int n, m, fr[NO], to[NO], f[NO], a[NO], cnt, head[NO], ot[NO];
bool book[NO];
struct node
{
	int nex, to;
}edge[NO << 1];
//variable

void add(int from, int to)
{
	edge[++cnt].nex = head[from];
	edge[cnt].to = to;
	head[from] = cnt;
}
int getf(int o)
{
	return f[o] == o ? o : f[o] = getf(f[o]);
}
void init()
{
    freopen("migration.in", "r", stdin);
    freopen("migration.out", "w", stdout);
	n = read(), m = read();
	fup (i, 1, m)
	{
		int x = read(), y = read();
		add(x, y), add(y, x);
	}
	fup (i, 1, n)
		a[i] = read();
	int ans = 0;
	fdn (i, n, 1)
	{
		ans++, f[a[i]] = a[i], book[a[i]] = true;
		for (int j = head[a[i]]; j; j = edge[j].nex)
			if (book[edge[j].to] && getf(a[i]) != getf(edge[j].to))
				f[getf(a[i])] = getf(edge[j].to), ans--;//, cout << "!!", ans--;
		// cout << ans << ' ';
		ot[i] = ans;
	}
	// lln;
	fup (i, 1, n)
		puts(ot[i] == 1 ? "YES" : "NO");
}
//functions

int main()
{
	init();
	return 0;
}
//main
/*
4 3
1 2
2 3
3 4
3
4
1
2

*/
