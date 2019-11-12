#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int pre[1001][1003], rank[1001][1003];
int ans[1001][1001], op[100001][6];

int Find_Set(int i, int x)    //并查集查找
{
    int now, res, bak;
    for (res = x; pre[i][res] != res; res = pre[i][res]);
    for (now = x; pre[i][now] != now; now = bak)
		bak = pre[i][now], pre[i][now] = res;
    return res;
}

void Union(int i, int x, int y)    //并查集合并
{
    x = Find_Set(i, x), y = Find_Set(i, y);
	pre[i][x] = y;
}

int main()
{
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
    int n, k, m, i, j, x1, y1, x2, y2, now;
    char ctrl[20];
    
    scanf("%d%d%d", &n, &k, &m);
    for (now = 0, i = 1; i <= m; i ++)
		{
			scanf("%s", ctrl);
			if (ctrl[0] == 'P')
				{
					op[i][0] = 1, scanf("%d", &op[i][1]);
					scanf("%d%d", &op[i][2], &op[i][3]);
					scanf("%d%d", &op[i][4], &op[i][5]);
				}
			if (ctrl[0] == 'S')
				op[i][0] = 2, op[i][1] = ++ now;
			if (ctrl[0] == 'L')
				op[i][0] = 3, scanf("%d", &op[i][1]);
		}
    
    for (i = 1; i <= n; i ++)
		for (j = 1; j <= n + 2; j ++)
			pre[i][j] = j, rank[i][j] = 0;
    for (i = 1; i <= n; i ++)
		for (j = 1; j <= n; j ++) ans[i][j] = 1;
    
    for (i = m; i; i --)
		{
			if (op[i][0] == 1)
				{
					x1 = op[i][2] + 1, y1 = op[i][3] + 1;
					x2 = op[i][4] + 1, y2 = op[i][5] + 1;
					for (j = x1; j <= x2; j ++)
						{
							if ((j - x1) % 2 == 0) now = y1; else now = y1 + 1;
							for (now = Find_Set(j, now); now <= y2; )
								{
									ans[j][now] = op[i][1];
									Union(j, now, now + 2);
									now = Find_Set(j, now);
								}
						}
				}
			if (op[i][0] == 3)
				for (now = op[i][1]; ; i --)
					if (op[i][0] == 2 && op[i][1] == now) break;
		}
    
    for (i = 1; i <= n; i ++)
		for (j = 1; j <= n; j ++)
			printf("%d%c", ans[i][j], (j < n) ? ' ' : '\n');
    
    return 0;
}
