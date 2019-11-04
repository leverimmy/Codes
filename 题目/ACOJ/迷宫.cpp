#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int sx,sy,fx,fy,n,m,t,ans;
int stone_x,stone_y;
int map[50][50];
bool book[50][50];
int zuobiao[4][2]=
{
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};
void dfs(int x,int y)
{
	if(x==fx && y==fy)
	{
		ans++;
		return;
	}
	int tempx=x,tempy=y;
	for(int r=0;r<=3;r++)
	{
		tempx+=zuobiao[r][0];
		tempy+=zuobiao[r][1];
		if(tempx>n || tempx<1 || tempy>m || tempy<1)
			continue;
		if(map[tempx][tempy]==0 && book[tempx][tempy]==0)
		{
			book[tempx][tempy]=1;
			dfs(tempx,tempy);
			book[tempx][tempy]=0;
		}
	}
	return;
}

int main()
{
	scanf("%d %d %d",&n,&m,&t);
	scanf("%d %d %d %d",&sx,&sy,&fx,&fy);
	for(int p=0;p<t;p++)
	{
		scanf("%d %d",&stone_x,&stone_y);
		map[stone_x][stone_y]=1;
	}
	map[sx][sy]=1;
	dfs(sx,sy);
	printf("%d",ans);
	return 0;
}