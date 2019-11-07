#include<iostream>
#define MAXn 402
#define MAXm 402
#define MAXs 402
using namespace std;
int n,m,s;
struct item {
	int v,w;
} a[MAXn][MAXm];
int dp[MAXn][MAXm][MAXs];
int main() {
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin>>a[i][j].v;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin>>a[i][j].w;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			for(int k=0; k<=s; k++) {
				if(a[i][j].v<=k)
					dp[i][j][k]=max(max(dp[i][j-1][k],dp[i][j-1][k-a[i][j].v]+a[i][j].w),
					                max(dp[i-1][j][k-a[i][j].v]+a[i][j].w,dp[i-1][j][k]));
				else dp[i][j][k]=max(dp[i][j-1][k],dp[i-1][j][k]);
			}
//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=m; j++)
//			cout<<dp[i][j][s]<<" ";
//		cout<<endl;
//	}
	cout<<dp[n][m][s];
	return 0;
}
/*
3 4 5
1 2 1 1
2 3 1 2
3 2 2 2
2 3 4 2
1 4 5 1
10 1 2 1
*/
