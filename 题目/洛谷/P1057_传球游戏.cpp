#include <cstdio>

using namespace std;

int n,m;
int dp[1010][1010];

int main()
{
	scanf("%d %d",&n,&m);
	dp[1][0]=1;
	for(int j=1;j<=m;j++)
	{
		for(int i=2;i<n;i++)
			dp[i][j]=dp[i-1][j-1]+dp[i+1][j-1];
		dp[1][j]=dp[n][j-1]+dp[2][j-1];
		dp[n][j]=dp[n-1][j-1]+dp[1][j-1];
	}
	printf("%d",dp[1][m]);
	return 0;
}