#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <iostream>

using namespace std;

int e[510][510],n,m,color,num,ans;
int book[510][510];

void init()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			book[i][j]=0;
}
void dfs(int x,int y)
{
	if(book[x][y]==-1)
		return;
	if(x==1 || x==n || y==1 || y==n)
	{
		color++;
		return;
	}
	book[x][y]=-1;
	if(x+1<n)
		dfs(x+1,y);
	if(x-1>1)
		dfs(x-1,y);
	if(y+1<n)
		dfs(x,y+1);
	if(y-1>1)
		dfs(x,y-1);
	return;
}

int main()
{
	scanf("%d %d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char t;
			scanf("%c",&t);
			if(t=='0')
				e[i][j]=1;
			else
				e[i][j]=0;
		}
		getchar();
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(e[i][j]==1)
			{
				init();
				dfs(i,j);
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(e[i][j]==-1)
				ans++;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%2d",e[i][j]);
		printf("\n");
	}
	printf("%d",num-ans);
	return 0;
}