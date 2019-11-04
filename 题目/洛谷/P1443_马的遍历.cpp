#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stdlib.h>
#include <queue>
using namespace std;
int n,m;
int ans[401][401];
queue<int> x;
queue<int> y;
int zh[8][2]={ 
    {1,2},
    {1,-2},
    {-1,2},
    {-1,-2},
    {2,1},
    {2,-1},
    {-2,1},
    {-2,-1}
};
void bfs(int a,int b)
{	int xx,yy,tx,ty;
	x.push(a);
	y.push(b);
	ans[a][b]=1;
	while(!x.empty())
	{xx=x.front();
	 yy=y.front();
	 x.pop();
	y.pop();
	for(int u=0;u<=7;u++)
		{	tx=xx+zh[u][0];
			ty=yy+zh[u][1];
			if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&!ans[tx][ty])
			{
				x.push(tx);
				y.push(ty);
				ans[tx][ty]=ans[xx][yy]+1;
			}	
		}	
	}
}
int main()
{
	int horx,hory;
	cin>>n>>m>>horx>>hory;
	bfs(horx,hory);
	for(int i=1;i<=n;i++)
	{for(int j=1;j<=m;j++)
		{
		printf("%-5d",ans[i][j]?ans[i][j]-1:-1);	
		}
		printf("\n");
	}
}