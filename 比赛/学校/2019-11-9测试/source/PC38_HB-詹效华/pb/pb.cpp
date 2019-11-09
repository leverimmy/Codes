#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int dp[101][101];
int a[101],sum[101];
signed main()
{
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	int n,w;
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=w;j++)
		{
			for(int k=0;k<i;k++)
				dp[i][j]=min(dp[i][j],dp[k][j-1]+i*(sum[i]-sum[k]));
		}
	}
	printf("%.4lf",(double)dp[n][w]/sum[n]);
}
/*
5 2
30 5 10 30 25
*/