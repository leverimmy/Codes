#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <iostream>
#include <queue>
#define il inline
#define rgi register int
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 20 + 10;
const int M = 20 + 10;

int n, m, ans = oo, startx, starty, endx, endy;
char op[5], tmp[N][M];
int to[5], go[5][2], e[N][M], vis[N][M][N][M];
// 0 -> .
// 1 -> #
// 2 -> H
// 3 -> P
// -1 -> !

struct nodes{ int lastxa, lastya, lastxb, lastyb, xa, ya, xb, yb, cur_ans; };

queue <struct nodes> q;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void prework()
{
	go[1][0] = -1, go[1][1] = 0;
	go[2][0] = 1, go[2][1] = 0;
	go[3][0] = 0, go[3][1] = -1;
	go[4][0] = 0, go[4][1] = 1;
}

bool ok(int x, int y)
{
	if(x < 1 || x > n || y < 1 || y > m || e[x][y])	return 0;
	return 1;
}

void bfs()
{
	q.push((nodes){0, 0, 0, 0, startx, starty, endx, endy, 0});
	while(!q.empty())
	{
		struct nodes cur = q.front(); q.pop();
		if(cur.xa == cur.xb && cur.ya == cur.yb)
		{
			ans = cur.cur_ans;
			return;
		}
		if(vis[cur.xa][cur.ya][cur.xb][cur.yb])	 continue;
		if(cur.xa == cur.lastxb && cur.ya == cur.lastyb && cur.xb == cur.lastxa && cur.yb == cur.lastya)
		{
			ans = cur.cur_ans;
			return;
		}
		vis[cur.xa][cur.ya][cur.xb][cur.yb] = 1;
		for(rgi i = 1; i <= 4; ++i)
		{
			if(ok(cur.xa + go[i][0], cur.ya + go[i][1]))
			{
				if(e[cur.xb + go[to[i]][0]][cur.yb + go[to[i]][1]] == 0)
					q.push((nodes){cur.xa, cur.ya, cur.xb, cur.yb, cur.xa + go[i][0], cur.ya + go[i][1], cur.xb + go[to[i]][0], cur.yb + go[to[i]][1], cur.cur_ans + 1});
				if(e[cur.xb + go[to[i]][0]][cur.yb + go[to[i]][1]] == 1)
					q.push((nodes){cur.xa, cur.ya, cur.xb, cur.yb, cur.xa + go[i][0], cur.ya + go[i][1], cur.xb, cur.yb, cur.cur_ans + 1});
			}
		}
	}
}

int main()
{
	freopen("escape.in", "r", stdin);
	freopen("escape.out", "w", stdout);
	n = read(), m = read();
	prework();
	for(rgi i = 1; i <= n; ++i)
		scanf("%s", tmp[i] + 1);
	scanf("%s", op + 1);
	for(rgi i = 1; i <= 4; ++i)
	{
		if(op[i] == 'N')	to[i] = 1;
		if(op[i] == 'S')	to[i] = 2;
		if(op[i] == 'W')	to[i] = 3;
		if(op[i] == 'E')	to[i] = 4;
	}
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j)
		{
			if(tmp[i][j] == '!')	e[i][j] = -1;
			if(tmp[i][j] == '#')	e[i][j] = 1;
			if(tmp[i][j] == 'H')	{ endx = i, endy = j; }
			if(tmp[i][j] == 'P')	{ startx = i, starty = j; }
		}
	/*for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= m; ++j)
			cout << setw(3) << e[i][j];
		cout << endl;
	}*/
	bfs();
	if(ans == oo)
		puts("Impossible");
	else
		printf("%d", ans);
	return 0;
}
/*
5 5
#####
#H..#
#.!.#
#.#P#
#####
WNSE

*/
