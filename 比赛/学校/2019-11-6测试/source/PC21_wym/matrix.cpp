#include<bits/stdc++.h>
using namespace std;
int n,m,s,dp[10][410][410];
struct node{
	int val,cst;
}mat[410][410];
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>mat[i][j].cst;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>mat[i][j].val;
	for(int siz=s;siz>=mat[1][1].cst;--siz)
		dp[1][1][siz]=mat[1][1].val;
//	for(int i=2;i<=n;++i)
//		for(int siz=s;siz>=mat[i][1].cst;--siz)
//			dp[i][1][siz]=max(dp[i-1][1][siz],dp[i-1][1][siz-mat[i][1].cst]+mat[i][1].val);
	for(int i=2;i<=m;++i)
		for(int siz=s;siz>=mat[1][i].cst;--siz)
			dp[1][i][siz]=max(dp[1][i-1][siz],dp[1][i-1][siz-mat[1][i].cst]+mat[1][i].val);
	for(int i=2;i<=n;++i){
		for(int j=2;j<=m;++j){
			for(int siz=s;siz>=mat[i][1].cst;--siz)
				dp[(i-1)%2+1][1][siz]=max(dp[((i-1)%2+1)^3][1][siz],dp[((i-1)%2+1)^3][1][siz-mat[i][1].cst]+mat[i][1].val);
			int maxlim=max(mat[i-1][j].cst,mat[i][j-1].cst);
			for(int siz=s;siz>=maxlim;siz--){
				dp[(i-1)%2+1][j][siz]=max(max(dp[((i-1)%2+1)^3][j][siz],dp[((i-1)%2+1)^3][j][siz-mat[i][j].cst]+mat[i][j].val),max(dp[(i-1)%2+1][j-1][siz],dp[(i-1)%2+1][j-1][siz-mat[i][j].cst]+mat[i][j].val));
//				dp[i][j][siz]=max(max(dp[i-1][j][siz],dp[i-1][j][siz-mat[i][j].cst]+mat[i][j].val),max(dp[i][j-1][siz],dp[i][j-1][siz-mat[i][j].cst]+mat[i][j].val));
			}
			int minlim=min(mat[i-1][j].cst,mat[i][j-1].cst);
			if(minlim==mat[i-1][j].cst)
				for(int siz=maxlim-1;siz>=minlim;siz--)
					dp[(i-1)%2+1][j][siz]=max(dp[((i-1)%2+1)^3][j][siz],dp[((i-1)%2+1)^3][j][siz-mat[i][j].cst]+mat[i][j].val);
			else
				for(int siz=maxlim-1;siz>=minlim;siz--)
					dp[(i-1)%2+1][j][siz]=max(dp[(i-1)%2+1][j-1][siz],dp[(i-1)%2+1][j-1][siz-mat[i][j].cst]+mat[i][j].val);
				
		}
	}
//	int ans=-1;
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=m;++j)
//			cout<<dp[i][j][s]<<' ';
//		cout<<endl;
//	}
//	for(int i=0;i<=s;++i){
//		ans=max(ans,dp[n][m][i]);
////		ans=max(ans,dp[(n-1)%2+1][m][i]);
//	}
	cout<<dp[(n-1)%2+1][m][s];
//	cout<<endl<<endl;
//	cout<<mat[2][1].val;
	return 0;
}
