#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
int n,m,t,sx,sy,fx,fy,stone_x,stone_y;
int ans;
int map[50][50];
int book[50][50];
int zuobiao[4][2]=
{
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};
void dfs(int x,int y,int steps)
{
	int tempx,tempy;
	if(x==fx && y==fy)
	{
		ans++;
		return;
	}
	for(int r=0;r<=3;r++)
	{
		tempx=x+zuobiao[r][0];
		tempy=y+zuobiao[r][1];
		if(tempx<1 || tempy<1 || tempx>n || tempy<m)
			continue;
		if(map[tempx][tempy]==0 && book[tempx][tempy]==0)
		{
			book[tempx][tempy]=1;
			dfs(tempx,tempy,steps+1);
			book[tempx][tempy]=0;
		}
	}
	return;
}
int main()
{
	scanf("%d %d %d",&n,&m,&t);
	scanf("%d %d %d %d",&sx,&sy,&fx,&fy);
	book[sx][sy]=1;
	for(int p=0;p<t;p++)
	{
		scanf("%d %d",&stone_x,&stone_y);
		map[stone_x][stone_y]=1;
	}
	dfs(sx,sy,0);
	printf("%d",ans);
	return 0;
}