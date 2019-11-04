#include<bits/stdc++.h>

#define int long long

using namespace std;

int a[1050][1050],n,m,dp[1050][1050][3];

signed main()
{
	freopen("lemouse.in","r",stdin);
	
	freopen("lemouse.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	
	for(int i=0;i<=n;i++) dp[i][1][0]=1e9;
	
	for(int i=0;i<=m;i++) dp[1][i][1]=1e9;
	
	dp[1][1][0]=dp[1][1][1]=a[1][1]+a[1][2]+a[2][1];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j!=1) dp[i][j][0]=min(dp[i][j-1][1]+a[i+1][j]+a[i][j+1],dp[i][j-1][0]+a[i+1][j]+a[i][j+1]+a[i-1][j]);
			
			if(i!=1) dp[i][j][1]=min(dp[i-1][j][1]+a[i+1][j]+a[i][j+1]+a[i][j-1],dp[i-1][j][0]+a[i+1][j]+a[i][j+1]);
		}
	}
	
	/*cout<<'\n';
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<dp[i][j][0]<<" "; 
		}
		cout<<endl;
	}
	cout<<'\n';
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<dp[i][j][1]<<" "; 
		}
		cout<<endl;
	}*/
	
	cout<<min(dp[n][m][0],dp[n][m][1]);
		
	return 0;
}

