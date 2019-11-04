#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n,i,j,t;
int map[40][40];

void dfs(int x,int y)
{
	if(x>=0 && x<=n+1 && y>=0 && y<=n+1)
	{
		if(map[x][y]==1 || map[x][y]==-1)
			return;
		else
		{
			map[x][y]=-1;
			dfs(x+1,y);
			dfs(x-1,y);
			dfs(x,y+1);
			dfs(x,y-1);
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&map[i][j]);
	dfs(0,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(map[i][j]==-1)
				map[i][j]=0;
			else if(map[i][j]==0)
				map[i][j]=2;
			}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",map[i][j]);
		printf("\n");
	}
	return 0;
}