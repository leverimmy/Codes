#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
#define NO 505
#define MO 300005
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
#define fup(i, x, y) for(register int i = x; i <= y; ++i)
#define lln putchar('\n')
#define blk putchar(' ')
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
ll read()
{
	ll ret = 0;
	char ch = ' ', last;
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ret = ((ret + (ret << 2)) << 1) + (ch ^ '0'), ch = getchar();
	return last == '-' ? -ret : ret;
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

int n, m, g[NO][NO];
bool book[NO][NO];
pii s, t;
string x;
priority_queue<piii, vector<piii>, greater<piii> > q;
priority_queue<piii> qq;
const int go[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
//variable

void init()
{
	freopen("escape.in", "r", stdin);
	freopen("escape.out", "w", stdout);
	memset(g, INF, sizeof(g));
	n = read(), m = read();
	fup (i, 1, n)
	{
		cin >> x;
		fup (j, 0, m - 1)
		{
			if (x[j] == 'V')
				s = mp(i, j + 1);
			else if (x[j] == 'J')
				t = mp(i, j + 1);
			else if(x[j] == '+')
				q.push(mp(0, mp(i, j + 1))), g[i][j + 1] = 0;
		}
	}
	while (!q.empty())
	{
		piii u = q.top();
		q.pop();
		if (book[u.se.fi][u.se.se])
			continue;
		book[u.se.fi][u.se.se] = true;
		fup (i, 0, 3)
		{
			pii v = mp(u.se.fi + go[i][0], u.se.se + go[i][1]);
			if (!book[v.fi][v.se] && v.fi <= n && v.fi >= 1 && v.se <= m && v.se >= 1)
				g[v.fi][v.se] = u.fi + 1, q.push(mp(g[v.fi][v.se], v));
		}
	}
	memset(book, false, sizeof(book));
	qq.push(mp(g[s.fi][s.se], s));
	while (!qq.empty())
	{
		piii u = qq.top();
		qq.pop();
		if (u.se == t)
			write(u.fi), lln, exit(0);
		if (book[u.se.fi][u.se.se])
			continue;
		book[u.se.fi][u.se.se] = true;
		fup (i, 0, 3)
		{
			pii v = mp(u.se.fi + go[i][0], u.se.se + go[i][1]);
			if (!book[v.fi][v.se] && v.fi <= n && v.fi >= 1 && v.se <= m && v.se >= 1)
				qq.push(mp(min(u.fi, g[v.fi][v.se]), v));
		}
	}
}
//functions

int main()
{
	init();
	return 0;
}
//main

