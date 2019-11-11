#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

const int Maxn = 1 << 30;

int n,m,dis[1010][1010];
int x1,Y1,x2,y2;
int stepx[4] = {1,-1,0,0},stepy[4] = {0,0,1,-1};
char ch[1010][1010];

void bfs()
{
	queue <int> Q1,Q2;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			{
				dis[i][j] = Maxn;
				if (ch[i][j] == 'V')    x1 = i,Y1 = j;
				if (ch[i][j] == 'J')    x2 = i,y2 = j;
				if (ch[i][j] == '+')    Q1.push(i),Q2.push(j),dis[i][j] = 0;
			}
	while (!Q1.empty())
		{
			int x = Q1.front(),y = Q2.front();
			Q1.pop();    Q2.pop();
			for (int i = 0;i <= 3;i++)
				{
					int xx = x + stepx[i],yy = y + stepy[i];
					if (dis[xx][yy] == Maxn)
						{
							dis[xx][yy] = dis[x][y] + 1;
							Q1.push(xx);    Q2.push(yy);
						}
				}
		}
}
int vis[1010][1010];
bool judge(int ans)
{
	queue <int> Q1,Q2;   memset(vis,0,sizeof (vis));
	Q1.push(x1);    Q2.push(Y1);    vis[x1][Y1] = 1;
	while (!Q1.empty())
		{
			int x = Q1.front(),y = Q2.front();
			if (x == x2 && y == y2)     return true;
			Q1.pop();    Q2.pop();
			for (int i = 0;i <= 3;i++)
				{
					int xx = x + stepx[i],yy = y + stepy[i];
					if (dis[xx][yy] >= ans && !vis[xx][yy])
						{
							Q1.push(xx);    Q2.push(yy);   vis[xx][yy] = 1;
						}
				}
		}
	return false;
}
void getans()
{
	int L = 0,R = dis[x1][Y1];
	while (L < R)
		{
			int mid = (L + R + 1) >> 1;
			if (judge(mid))     L = mid;
			else R = mid - 1;
		}
	cout << L;
}

int main()
{
	freopen("escape.in","r",stdin);     freopen("escape.out","w",stdout);
	cin >> n >>m;
	for (int i = 1;i <= n;i++)
		scanf("%s",ch[i]);
	bfs();
	getans();
}
