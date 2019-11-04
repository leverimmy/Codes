#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int num[1100][1100];
int dp[1100][1100];
int i,j,n;
int maxnum(int i,int j)
{
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(i==n)
		dp[i][j]=num[i][j];
	else
		dp[i][j]=max(maxnum(i+1,j),maxnum(i+1,j+1))+num[i][j];
	return dp[i][j];
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			scanf("%d",&num[i][j]);
	memset(dp,-1,sizeof(dp));
	printf("%d", maxnum(1,1));
	return 0;
}