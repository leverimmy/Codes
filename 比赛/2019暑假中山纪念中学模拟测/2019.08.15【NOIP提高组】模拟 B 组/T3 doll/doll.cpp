#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int
#define rgl register ll

using namespace std;

const int N = 50 + 10;
const int M = 50 + 10;

int n, m, r, c, tot, ans;
int dx[5], dy[5];
int e[N][M], vis[N][M], map[N][M][3];
char tmp[N][M];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool dfs(int x, int y)
{
	for(rgi i = 1; i <= 4; ++i)
	{
		int cur_x = x + dx[i];
		int cur_y = y + dy[i];
		if(e[cur_x][cur_y] && !vis[cur_x][cur_y])
		{
			vis[cur_x][cur_y] = 1;
			if(map[cur_x][cur_y][1] == 0 || dfs(map[cur_x][cur_y][1], map[cur_x][cur_y][2]))
			{
				map[cur_x][cur_y][1] = x;
				map[cur_x][cur_y][2] = y;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
//	freopen("doll2.in", "r", stdin);
	n = read(), m = read(), r = read(), c = read();
	for(rgi i = 1; i <= n; ++i)
		scanf("%s", tmp[i] + 1);
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j)
		{
			if(tmp[i][j] == '.')
				e[i][j] = 1, tot++;
			else
				e[i][j] = 0;
		}
	/*for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= m; ++j)
			printf("%d", e[i][j]);
		puts("");
	}*/
	if(r == c)
	{
		dx[1] = r, dx[2] = 50, dx[3] = r, dx[4] = 50;
		dy[1] = c, dy[2] = 50, dy[3] = -c, dy[4] = 50;
	}
	else
	{
		dx[1] = r, dx[2] = r, dx[3] = c, dx[4] = c;
		dy[1] = c, dy[2] = -c, dy[3] = r, dy[4] = -r;
	}
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j)
		{
			if(e[i][j])
			{
				memset(vis, 0, sizeof(vis));
				if(dfs(i, j))
					ans++;
			}
		}
	printf("%d", tot - ans);
	return 0;
}

