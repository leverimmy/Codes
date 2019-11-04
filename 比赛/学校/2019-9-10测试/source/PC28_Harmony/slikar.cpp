#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#define NO 55
#define INF 0x3f3f3f3f
#define fi first
#define se second 
#define lln putchar('\n')
#define blk putchar(' ')
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii;
typedef pair<pair<int, int>, pair<int, int> >piii;
ll read()
{
	char ch = ' ', last;
	ll ret = 0;
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ret = (ret << 3) + (ret << 1) + ch - '0', ch = getchar();
	if (last == '-')
		return -ret;
	return ret;
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

const int go[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int map[NO][NO], n, m, cnt, ans;
bool book[NO][NO], vis[NO][NO];
pii s, e, w[NO *NO];
priority_queue<piii, vector<piii>, greater<piii> >q;
//variable

void init()
{
	freopen("slikar.in", "r", stdin);
	freopen("sliker.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			char ch = getchar();
			while (ch == ' ' || ch == '\n')
				ch = getchar();
			if (ch == 'X')
				map[i][j] = -1;
			if (ch == 'D')
				e = mp(i, j), map[i][j] = -1;
			if (ch == 'S')
				s = mp(i, j);
			if (ch == '*')
				w[++cnt] = mp(i, j), book[i][j] = true;
//			cout <<i << ',' <<j <<endl;
		}
	q.push(mp(mp(0, 0), s));
	for (int i = 1; i <= cnt; i++)
		q.push(mp(mp(0, 1), w[i]));
	while (!q.empty())
	{
		int ty = q.top().fi.se, t = q.top().fi.fi;
		pii cur = q.top().se;
		q.pop();
		if (book[cur.fi][cur.se] && !ty)
			continue;
		if (!ty && cur == e)
		{
			ans = t;
			break;
		}
//		cout << ty << ',' << t <<',' << "p::" << cur.fi <<',' << cur.se <<endl;
		for (int i = 0; i < 4; i++)
		{
			pii nex = mp(cur.fi + go[i][0], cur.se + go[i][1]);
			if ((vis[nex.fi][nex.se] & !ty) || book[nex.fi][nex.se] || (map[nex.fi][nex.se] == -1 & ty) || nex.fi < 1 || nex.fi > n || nex.se < 1 || nex.se > m)
				continue;
			book[nex.fi][nex.se] = ty, vis[nex.fi][nex.se] = !ty, q.push(mp(mp(t + 1, ty), nex));
		}
//		for (int i = 1; i <= n; i++, lln)
//			for (int j = 1; j <= n; j++)
//				write(book[i][j]);
//		lln;
//		for (int i = 1; i <= n; i++, lln)
//			for (int j = 1; j <= n; j++)
//				write(vis[i][j]);
	}
	if (!ans)
		puts("ORZ hzwer!!!");
	else
		write(ans), lln;
}
//functions

int main()
{
	init();
	return 0;
}
//main
/*
3 6
D...*.
.X.X..
....S.
*/
