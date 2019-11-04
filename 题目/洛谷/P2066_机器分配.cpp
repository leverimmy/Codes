#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n,m;
int profit[110][110];
int dp[110][110];
int maxl;
void show(int i,int j)
{
	int t;
	if(i==0)
		return;
	for(t=0;t<=j;t++)
	{
		if(maxl==dp[i-1][t]+profit[i][j-t]);
		{
			maxl=dp[i-1][t];
			show(i-1,t);
			printf("%d %d\n",i,j-t);
			break;
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&profit[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			maxl=0;
			for(int k=0;k<=j;k++)
				if(maxl<dp[i-1][k]+profit[i][j-k])
					maxl=dp[i-1][k]+profit[i][j-k];
			dp[i][j]=maxl;
		}
	printf("%d\n",dp[n][m]);
	show(n,m);
	return 0;
}