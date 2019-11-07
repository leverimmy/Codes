#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int a[101][101];

signed main()
{
	freopen("16.in","r",stdin);
	freopen("16.out","w",stdout);
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1;i<=x;i++)
		a[i][1]=n++;
	for(int i=2;i<=x;i++)
		a[x][i]=n++;
	for(int i=x-1;i>=1;i--)
		a[i][x]=n++;
	for(int i=x-1;i>=2;i--)
		a[1][i]=n++;
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=x;j++)
			if(a[i][j]==0)
				printf("   ");
			else
				printf("%d ",a[i][j]);
				printf("\n");
			}
	return 0;
}