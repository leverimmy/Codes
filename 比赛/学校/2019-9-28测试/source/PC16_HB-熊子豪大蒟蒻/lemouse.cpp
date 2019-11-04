//dp pre 100 
#include<bits/stdc++.h>
using namespace std;
int n,m;
bool a[1001][1001];
int dp[1001][1001][2];
int main(){
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	dp[0][0][0]=dp[0][0][1]=a[0][0]+a[0][1]+a[1][0];
	for(int i=1;i<n;i++){
		dp[i][0][0]=dp[i-1][0][0]+a[i+1][0]+a[i][1];
		dp[i][0][1]=19260817;
	}
	for(int i=1;i<m;i++){
		dp[0][i][1]=dp[0][i-1][1]+a[1][i]+a[0][i+1];
		dp[0][i][0]=19260817;
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			dp[i][j][0]=min(dp[i-1][j][0]+a[i][j-1],dp[i-1][j][1])+a[i][j+1]+a[i+1][j];
			dp[i][j][1]=min(dp[i][j-1][1]+a[i-1][j],dp[i][j-1][0])+a[i][j+1]+a[i+1][j];
		}
	}
	cout<<min(dp[n-1][m-1][0],dp[n-1][m-1][1]);
	return 0;
}

