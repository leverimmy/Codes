#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[401][401];
int f[401][401];
int v[401][401];
int w[401][401];
signed main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n,m,s;
	scanf("%lld%lld%lld",&n,&m,&s);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%lld",&w[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%lld",&v[i][j]);
	f[1][w[1][1]]=v[1][1];
	for(int i=1;i<n;i++)
	{
		memset(dp,0,sizeof(dp));
		for(int j=1;j<m;j++)
			for(int k=s;k>=0;k--)
			{
				f[j+1][k]=max(f[j+1][k],f[j][k]);
				if(k+w[i][j+1]<=s) 
					f[j+1][k+w[i][j+1]]=max(f[j+1][k+w[i][j+1]],f[j][k]+v[i][j+1]);
			}
		for(int j=1;j<=m;j++)
			for(int k=s;k>=0;k--)
			{
				dp[j][k]=max(f[j][k],dp[j][k]);
				if(k+w[i+1][j]<=s)
					dp[j][k+w[i+1][j]]=max(dp[j][k+w[i+1][j]],f[j][k]+v[i+1][j]);
			}
		swap(f,dp);
	}
	int ans=0;
	for(int i=s;i>=0;i--)
		ans=max(ans,f[m][i]);
	printf("%lld",ans);
	return 0;
}
/*
4
1 4
3 2
5 2
2 1
*/