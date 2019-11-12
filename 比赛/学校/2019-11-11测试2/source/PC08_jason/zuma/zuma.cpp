#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[101];
int dp[101][101];
int sum[101][101];
const int inf=999999999;
int get(int l,int r,int x)
{
	int f[101][7];
	memset(f,0x3f,sizeof(f));
	vector<int>v;
	v.push_back(l-1);
	for(int i=l;i<=r;i++)
		if(a[i]==x)
			v.push_back(i);
	for(int i=1;i<v.size();i++)
		f[i][1]=dp[l][v[i]-1];
	for(int t=2;t<k;t++)
	{
		for(int i=0;i<v.size();i++)
		{
			int atr=v[i];
			for(int j=0;j<i;j++)
			{
				int atl=v[j];
				f[atr][t]=min(f[atr][t],f[atl][t-1]+dp[atl+1][atr-1]);
			}
		}
	}
	for(int i=0;i<v.size();i++)
	{
		int atr=v[i];
		for(int j=0;j<v.size();j++)
		{
			int atl=v[j];
			f[atr][k]=min(f[atr][k],f[atl][k-1]+min(dp[atl+1][k-1],dp[atl+1][k]));
		}
	}

	int ans=k;
	for(int i=0;i<k;i++)
		ans=min(ans,dp[v[v.size()-1]+][i]+k-i);
	return ans+dp[v.back()+1][r];
}
signed main()
{
	freopen("zuma.in","r",stdin);
	freopen("zuma.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=1;j<=n;j++)
			sum[i][j]=sum[i-1][j];
		sum[i][a[i]]++;
	}
	for(int i=1;i<=n;i++)
		dp[i][i]=k-1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<n-i+1;j++)
		{
			for(int t=1;t<=n;t++)
				if(sum[i+j-1][t]!=sum[i-1][t])
					dp[i][i+j-1]=get(i,i+j-1,t);
		}
	printf("%d",dp[1][n]);
	return 0;
}
