#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int a[MAXN],dp[MAXN];
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	int N,M;
	scanf("%d",&N);
	if(N<=100)
	{
		for(int i=1;i<=N;i++)
		{
			scanf("%d",a+i);
		}
		scanf("%d",&M);
		for(int i=1;i<=M;i++)
		{
			int P,K;
			scanf("%d%d",&P,&K);
			int NowNode=P;
			int now=0;
			while(NowNode<=N)
			{
				now++;
				NowNode=a[NowNode]+NowNode+K; 
			}
			printf("%d\n",now);
		}
	}
	else
	{
		for(int i=1;i<=N;i++)
		{
			scanf("%d",a+i);
		}
		for(int i=N;i>=1;i--)
		{
			if(i+a[i]>N)
			{
				dp[i]=1;
			}
			else
			{
				dp[i]=dp[i+a[i]]+1;
			}
		}
		scanf("%d",&M);
		for(int i=1;i<=M;i++)
		{
			int P,K;
			scanf("%d%d",&P,&K);
			printf("%d\n",dp[P]);
		}
	}
	return 0;
}
