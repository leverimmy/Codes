#include <bits/stdc++.h>
using namespace std;
int N,S;
int _map[100][100];
void DFS(int x,int y,int now)//x--zong y--heng
{
	if(_map[x][y])
	{
		return;
	}
	_map[x][y]=now;
	if(y==1&&x!=S)
	{
		DFS(x+1,y,now+1);
		return;
	}
	if(x==S&&y!=S)
	{
		DFS(x,y+1,now+1);
		return;
	}
	if(y==S&&x!=1)
	{
		DFS(x-1,y,now+1);
		return;
	}
	if(x==1&&y!=1)
	{
		DFS(x,y-1,now+1);
		return;
	}
}
int main()
{
	freopen("16.in","r",stdin);
	freopen("16.out","w",stdout);
	scanf("%d%d",&N,&S);
	DFS(1,1,N);
	for(int i=1;i<=S;i++)
	{
		for(int j=1;j<=S;j++)
		{
			if(!_map[i][j])
			{
				printf("   ");
			}
			else
			{
				printf("%d ",_map[i][j]);
			}
		}
		putchar('\n');
	}
	return 0;
}

