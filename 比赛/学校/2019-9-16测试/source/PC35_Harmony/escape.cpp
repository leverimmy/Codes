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
#include <deque>
#define INF 0x3f3f3f3f
#define MO 200005
#define NO 25
#define eps 1e-9
#define P 998244353ll
#define fup(i, x, y) for (ll i = x; i <= y; i++)
#define fdn(i, x, y) for (ll i = x; i >= y; i--)
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

int n, m, map[NO][NO];
pii a, b;
int goa[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }, gob[4][2];
bool book[NO][NO][NO][NO];
queue<pair<pii, pair<pii, int> > > q;
//variable

inline bool in(pii x, bool f)
{
	if (x.fi > n || x.fi < 1 || x.se > m || x.se < 1)
		return false;
	if (map[x.fi][x.se] == -1)
		return false;
	if (f && map[x.fi][x.se] == 1)
		return false;
	return true;
}
void init()
{
	n = read(), m = read();
	fup (i, 1, n)
		fup (j, 1, m)
		{
			char ch = getchar();
			while (ch == '\n' || ch == ' ')
				ch = getchar();
			if (ch == '!')
				map[i][j] = -1;
			else if(ch == '#')
				map[i][j] = 1;
			else if (ch == 'P')
				a = mp(i, j);
			else if (ch == 'H')
				b = mp(i, j);
		}
	string x;
	cin >> x;
	fup (i, 0, 3)
	{
		if (x[i] == 'N')
			gob[i][0] = goa[0][0], gob[i][1] = goa[0][1];
		else if (x[i] == 'S')
			gob[i][0] = goa[1][0], gob[i][1] = goa[1][1];
		else if (x[i] == 'W')
			gob[i][0] = goa[2][0], gob[i][1] = goa[2][1];
		else if (x[i] == 'E')
			gob[i][0] = goa[3][0], gob[i][1] = goa[3][1];
	}
}
//functions

int main()
{
	freopen("escape.in", "r", stdin);
	freopen("escape.out", "w", stdout);
	init();
	q.push(mp(a, mp(b, 0)));
	while (!q.empty())
	{
		pii cura = q.front().fi, curb = q.front().se.fi;
		int t = q.front().se.se;
//		cout << cura.fi << ',' << cura.se << ' ' << curb.fi << ',' << curb.se << endl;
		q.pop();
		if (book[cura.fi][cura.se][curb.fi][curb.se])
			continue;
		book[cura.fi][cura.se][curb.fi][curb.se] = true;
		if (cura == curb)
		{
			write(t), lln;
			return 0;
		}
		fup (i, 0, 3)
		{
			pii nexa = mp(cura.fi + goa[i][0], cura.se + goa[i][1]), nexb = mp(curb.fi + gob[i][0], curb.se + gob[i][1]);
			if (!in(nexa, 1) || !in(nexb, 0))
				continue;
			if (map[nexb.fi][nexb.se])
				nexb = curb;
			q.push(mp(nexa, mp(nexb, t + 1)));
		}
	}
	puts("Impossible");
	return 0;
}
//main
