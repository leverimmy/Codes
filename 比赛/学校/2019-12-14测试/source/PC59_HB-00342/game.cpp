#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int a[101];
int dp[10001][21];
int n,s;
int dfs(int val,int x)
{
	if(dp[val][x]!=-1)return dp[val][x];
	if(x==n+1)return dfs(val,1);
	if(val==0)return x%2;
	for(int i=1;i<=min(val,a[x]);i++)
		if(dfs(val-i,x+1)==x%2)
			return dp[val][x]=x%2;
	return dp[val][x]=(x+1)%2;
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	while(1)
	{
		scanf("%d",&n);
		if(!n) return 0;
		scanf("%d",&s);
		n*=2;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(dp,-1,sizeof(dp));
		printf("%d\n",dfs(s,1));
	}
	return 0;
}
/*
1 9 4 4 
1 101 4 4
1 100 4 4 
3 97 8 7 6 5 4 3
0
*/