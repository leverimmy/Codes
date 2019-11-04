#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
int dp[1001][1001][2];//0 right   1 down
int r[1001][1001][2];
int d[1001][1001][2];

signed main()
{
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			r[i][j][0]=a[i-1][j]+a[i][j+1]+a[i+1][j];
			r[i][j][1]=a[i+1][j]+a[i][j+1];
			d[i][j][0]=a[i+1][j]+a[i][j+1];
			d[i][j][1]=a[i][j-1]+a[i+1][j]+a[i][j+1];
		}
	memset(dp,0x3f,sizeof(dp));
	dp[1][1][0]=dp[1][1][1]=a[1][1]+a[1][2]+a[2][1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(j>1)
				dp[i][j][0]=min(dp[i][j-1][1]+r[i][j][1],dp[i][j-1][0]+r[i][j][0]);
			if(i>1)
				dp[i][j][1]=min(dp[i-1][j][1]+d[i][j][1],dp[i-1][j][0]+d[i][j][0]);
		}
	
	printf("%d",min(dp[n][m][0],dp[n][m][1]));
	
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",min(dp[i][j][0],dp[i][j][1]));
		printf("\n");
	}*/
	return 0;
}