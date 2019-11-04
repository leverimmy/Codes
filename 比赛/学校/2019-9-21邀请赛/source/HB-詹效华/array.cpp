#include <bits/stdc++.h>
using namespace std;
int dp[100002][410];
int a[100002];
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int k=1;k<=sqrt(n);k++)
	{
		for(int i=n;i>=1;i--)
			dp[i][k]=dp[min(n+1,i+a[i]+k)][k]+1;
	}
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int x,k;
		scanf("%d%d",&x,&k);
		if(k<=sqrt(n))
			printf("%d\n",dp[x][k]);
		else
		{
			int ans=0;
			while(x<=n)
				ans++,x+=a[x]+k;
			printf("%d\n",ans);
		}
	}
	return 0;
}