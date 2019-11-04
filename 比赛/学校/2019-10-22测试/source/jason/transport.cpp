#include<bits/stdc++.h>
using namespace std;
int x[501],y[501];
int dp[501][1001];
signed main()
{
	freopen("transport.in","r",stdin);
	freopen("transport.out","w",stdout);
	int n,t;
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	memset(dp,0x3f,sizeof(dp));
	dp[1][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			for(int k=0;k<=t;k++)
				dp[i][k+i-j-1]=min(dp[i][k+i-j-1],dp[j][k]+abs(x[i]-x[j])+abs(y[i]-y[j]));
	printf("%d",dp[n][t]);
	return 0;
}
