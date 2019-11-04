#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=2000005;

typedef long long fhk;

fhk a[MAXN],ans;
fhk dp[MAXN][8][4];//dp[i][j][k]表示前i个用第j个队，是否选第i人(k==1选，k==0不选)最大美丽度 
int main()
{
	freopen("jx.in","r",stdin);
	freopen("jx.out","w",stdout);
	fhk N;
	scanf("%lld",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%lld",a+i);
	}
	for(int i=1;i<=N;i++)
	{
		dp[i][0][0]=0;
		dp[i][1][1]=max(dp[i-1][1][1],dp[i-1][0][0])+a[i];
//		printf("%d %d %d %d %d\n",dp[i-1][1][1],dp[i-1][0][0],max(dp[i-1][1][1],dp[i-1][0][0]),a[i],dp[i][1][1]);
		dp[i][1][0]=max(dp[i-1][1][1],dp[i-1][1][0]);
		dp[i][2][1]=max(dp[i-1][2][1],dp[i-1][1][0])+a[i];
		dp[i][2][0]=max(dp[i-1][2][1],dp[i-1][2][0]);
		dp[i][3][1]=max(dp[i-1][3][1],dp[i-1][2][0])+a[i];
		dp[i][3][0]=max(dp[i-1][3][1],dp[i-1][3][0]);
//		printf("%lld %lld %lld %lld %lld %lld %lld\n",dp[i][1][0],dp[i][1][1],dp[i][2][0],dp[i][2][1],dp[i][3][0],dp[i][3][1],a[i]);
		ans=max(max(max(max(max(dp[i][1][0],dp[i][1][1]),dp[i][2][0]),dp[i][2][1]),dp[i][3][0]),dp[i][3][1]);
	}
	printf("%lld",ans);
	return 0;
}
