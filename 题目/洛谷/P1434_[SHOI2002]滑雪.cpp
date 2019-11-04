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

int ans=-100;
int f[150][150];
int e[150][150];
int r,c;

int dfs(int x,int y)
{
	int ans=1;
	if(f[x][y])
		return f[x][y];
	if(x-1>0 && e[x-1][y]<e[x][y])
		ans=max(ans,dfs(x-1,y)+1);
	if(y-1>0 && e[x][y-1]<e[x][y])
		ans=max(ans,dfs(x,y-1)+1);
	if(x+1<=r && e[x+1][y]<e[x][y])
		ans=max(ans,dfs(x+1,y)+1);
	if(y+1<=c && e[x][y+1]<e[x][y])
		ans=max(ans,dfs(x,y+1)+1);
	return f[x][y]=ans;
}

int main()
{
	scanf("%d %d",&r,&c);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			scanf("%d",&e[i][j]);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			ans=max(ans,dfs(i,j));
	printf("%d",ans);
	return 0;
}