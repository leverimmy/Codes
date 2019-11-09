#include <bits/stdc++.h>
using namespace std;
const int MAXN=4000005;
int a[MAXN];
int sta[MAXN],top;
int dp[MAXN][2];//0--unused 1--used
int l[MAXN];
int ans;
int main()
{
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=1;i<=N;i++)
	{
		while(top&&a[sta[top]]>=a[i])
		{
			top--;
		}
		l[i]=sta[top];
		top++;
		sta[top]=i;
	}
	for(int i=1;i<=N;i++)
	{
		if(a[i]>a[i-1])
		{
			dp[i][0]=dp[i-1][0]+1;
			dp[i][1]=dp[i-1][1]+1;
		}
		else
		{
			dp[i][0]=1;
		}
		for(int j=1;j<i;j++)
		{
			if(a[j]<a[i])
			{
				dp[i][1]=max(dp[i][1],dp[i][0]+1);
			}
		}
		ans=max(max(ans,dp[i][1]),dp[i][0]);
	}
	printf("%d",ans);
	return 0;
}
