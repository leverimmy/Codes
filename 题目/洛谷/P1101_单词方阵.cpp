#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n,tempx,tempy;
char map[110][110];
bool printmap[110][110];
char word[6]={'i','z','h','o','n','g'};
int xyxy[8][2]={
	{1,0},
	{0,1},
	{1,1},
	{1,-1},
	{-1,1},
	{-1,-1},
	{0,-1},
	{-1,0},
};
void color(int x,int y,int step,int t)
{
	if(step>=7)
		return;
	printmap[x][y]=1;
	tempx=x+xyxy[t][0];
	tempy=y+xyxy[t][1];
	color(tempx,tempy,step+1,t);
}
void dfs(int nx,int ny,int step,int t)
{
	if(nx<0 || ny<0 || nx>n || ny>n)
		return;
	if(step>=6)
	{
		color(nx,ny,0,7-t);
		return;
	}
	tempx=nx+xyxy[t][0];
	tempy=ny+xyxy[t][1];
	if(map[tempx][tempy]!=word[step])
		return;
	else
		dfs(tempx,tempy,step+1,t);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=0;j<n;j++)
			scanf("%c",&map[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<n;j++)
			if(map[i][j]=='y')
			{
				for(int h=0;h<=7;h++)
					dfs(i,j,0,h);
			}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(printmap[i][j]==1)
				printf("%c",map[i][j]);
			else
				printf("*");
		}
		printf("\n");
	}
	return 0;
}