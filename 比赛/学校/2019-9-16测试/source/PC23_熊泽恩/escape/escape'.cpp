#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <iostream>
#include <iomanip>
#define il inline
#define rgi register int
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 20 + 10;
const int M = 20 + 10;

int n, m, ans = oo;
char op[5], tmp[N][M];
int to[5], e[N][M], vis1[N][M], vis2[N][M];
// 0 -> .
// 1 -> #
// 2 -> H
// 3 -> P
// -1 -> !

struct node
{
	int x, y;
} start, end;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int px, int py, int hx, int hy, int cur_ans, int move)
{
	if(vis1[px][py] && !move)	return;
	if(vis1[px][py] && vis2[hx][hy] && move)	return;
	vis1[px][py] = vis2[hx][hy] = 1;
	if(cur_ans >= ans)	return;
	if(px == hx && py == hy)
	{
		ans = min(ans, cur_ans);
		return;
	}
	if(px - 1 <= n && px - 1 >= 1 && !e[px - 1][py])//paris 往上走
	{
		int cur_direction = to[1];
		if(cur_direction == 1)
		{
			if(hx - 1 <= n && hx - 1 >= 1)
			{
				if(e[hx - 1][hy] == 0)
					dfs(px - 1, py, hx - 1, hy, cur_ans + 1, move | 1);
				if(e[hx - 1][hy] == 1)
					dfs(px - 1, py, hx, hy, cur_ans + 1, move);
			}
		}
		if(cur_direction == 2)
		{
			if(hx + 1 <= n && hx + 1 >= 1)
			{
				if(e[hx + 1][hy] == 0)
					dfs(px - 1, py, hx + 1, hy, cur_ans + 1, move | 1);
				if(e[hx + 1][hy] == 1)
					dfs(px - 1, py, hx, hy, cur_ans + 1, move);
			}
		}
		if(cur_direction == 3)
		{
			if(hy - 1 <= m && hy - 1 >= 1)
			{
				if(e[hx][hy - 1] == 0)
					dfs(px - 1, py, hx, hy - 1, cur_ans + 1, move | 1);
				if(e[hx][hy - 1] == 1)
					dfs(px - 1, py, hx, hy, cur_ans + 1, move);
			}
		}
		if(cur_direction == 4)
		{
			if(hy + 1 <= m && hy + 1 >= 1)
			{
				if(e[hx][hy + 1] == 0)
					dfs(px - 1, py, hx, hy + 1, cur_ans + 1, move | 1);
				if(e[hx][hy + 1] == 1)
					dfs(px - 1, py, hx, hy, cur_ans + 1, move);
			}
		}
	}
	if(px + 1 <= n && px + 1 >= 1 && !e[px + 1][py])//paris 往下走
	{
		int cur_direction = to[2];
		if(cur_direction == 1)
		{
			if(hx - 1 <= n && hx - 1 >= 1)
			{
				if(e[hx - 1][hy] == 0)
					dfs(px + 1, py, hx - 1, hy, cur_ans + 1, move | 1);
				if(e[hx - 1][hy] == 1)
					dfs(px + 1, py, hx, hy, cur_ans + 1, move);
			}
		}
		if(cur_direction == 2)
		{
			if(hx + 1 <= n && hx + 1 >= 1)
			{
				if(e[hx + 1][hy] == 0)
					dfs(px + 1, py, hx + 1, hy, cur_ans + 1, move | 1);
				if(e[hx + 1][hy] == 1)
					dfs(px + 1, py, hx, hy, cur_ans + 1, move);
			}
		}
		if(cur_direction == 3)
		{
			if(hy - 1 <= m && hy - 1 >= 1)
			{
				if(e[hx][hy - 1] == 0)
					dfs(px + 1, py, hx, hy - 1, cur_ans + 1, move | 1);
				if(e[hx][hy - 1] == 1)
					dfs(px + 1, py, hx, hy, cur_ans + 1, move);
			}
		}
		if(cur_direction == 4)
		{
			if(hy + 1 <= m && hy + 1 >= 1)
			{
				if(e[hx][hy + 1] == 0)
					dfs(px + 1, py, hx, hy + 1, cur_ans + 1, move | 1);
				if(e[hx][hy + 1] == 1)
					dfs(px + 1, py, hx, hy, cur_ans + 1, move);
			}
		}
	}
	if(py - 1 <= m && py - 1 >= 1 && !e[px][py - 1])//paris 往左走
	{
		int cur_direction = to[3];
		if(cur_direction == 1)
		{
			if(hx - 1 <= n && hx - 1 >= 1)
			{
				if(e[hx - 1][hy] == 0)
					dfs(px, py - 1, hx - 1, hy, cur_ans + 1, move | 1);
				if(e[hx - 1][hy] == 1)
					dfs(px, py - 1, hx, hy, cur_ans + 1, move);
			}
		}
		if(cur_direction == 2)
		{
			if(hx + 1 <= n && hx + 1 >= 1)
			{
				if(e[hx + 1][hy] == 0)
					dfs(px, py - 1, hx + 1, hy, cur_ans + 1, move | 1);
				if(e[hx + 1][hy] == 1)
					dfs(px, py - 1, hx, hy, cur_ans + 1, move);
			}
		}
		if(cur_direction == 3)
		{
			if(hy - 1 <= m && hy - 1 >= 1)
			{
				if(e[hx][hy - 1] == 0)
					dfs(px, py - 1, hx, hy - 1, cur_ans + 1, move | 1);
				if(e[hx][hy - 1] == 1)
					dfs(px, py - 1, hx, hy, cur_ans + 1, move);
			}
		}
		if(cur_direction == 4)
		{
			if(hy + 1 <= m && hy + 1 >= 1)
			{
				if(e[hx][hy + 1] == 0)
					dfs(px, py - 1, hx, hy + 1, cur_ans + 1, move | 1);
				if(e[hx][hy + 1] == 1)
					dfs(px, py - 1, hx, hy, cur_ans + 1, move);
			}
		}
	}
	if(py + 1 <= m && py + 1 >= 1 && !e[px][py + 1])//paris 往右走
	{
		int cur_direction = to[4];
		if(cur_direction == 1)
		{
			if(hx - 1 <= n && hx - 1 >= 1)
			{
				if(e[hx - 1][hy] == 0)
					dfs(px, py + 1, hx - 1, hy, cur_ans + 1, move | 1);
				if(e[hx - 1][hy] == 1)
					dfs(px, py + 1, hx, hy, cur_ans + 1, move);
			}
		}
		if(cur_direction == 2)
		{
			if(hx + 1 <= n && hx + 1 >= 1)
			{
				if(e[hx + 1][hy] == 0)
					dfs(px, py + 1, hx + 1, hy, cur_ans + 1, move | 1);
				if(e[hx + 1][hy] == 1)
					dfs(px, py + 1, hx, hy, cur_ans + 1, move);
			}
		}
		if(cur_direction == 3)
		{
			if(hy - 1 <= m && hy - 1 >= 1)
			{
				if(e[hx][hy - 1] == 0)
					dfs(px, py + 1, hx, hy - 1, cur_ans + 1, move | 1);
				if(e[hx][hy - 1] == 1)
					dfs(px, py + 1, hx, hy, cur_ans + 1, move);
			}
		}
		if(cur_direction == 4)
		{
			if(hy + 1 <= m && hy + 1 >= 1)
			{
				if(e[hx][hy + 1] == 0)
					dfs(px, py + 1, hx, hy + 1, cur_ans + 1, move | 1);
				if(e[hx][hy + 1] == 1)
					dfs(px, py + 1, hx, hy, cur_ans + 1, move);
			}
		}
	}
	vis1[px][py] = vis2[hx][hy] = 0;
}

int main()
{
	n = read(), m = read();
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
			if(tmp[i][j] == 'H')	{ end.x = i, end.y = j; }
			if(tmp[i][j] == 'P')	{ start.x = i, start.y = j; }
		}
	/*for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= m; ++j)
			cout << setw(3) << e[i][j];
		cout << endl;
	}*/
	dfs(start.x, start.y, end.x, end.y, 0, 0);
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
