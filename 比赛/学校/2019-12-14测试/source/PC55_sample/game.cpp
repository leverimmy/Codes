#include <bits/stdc++.h>
#define rgi register int
using namespace std;
const int maxn=30;
const int maxs=10005;
int n,s,a[maxn],dp[maxs][maxn];
int dfs(int sum,int x)
{
	if(~dp[sum][x])
		return dp[sum][x];
	if(x==n+1)
		return dfs(sum,1);
	if(!sum)
		return dp[sum][x]=(x&1);
	for(rgi i=1;i<=min(a[x],sum);++i)
		if(dfs(sum-i,x+1)==(x&1))
			return dp[sum][x]=(x&1);
	return dp[sum][x]=((x+1)&1);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	while(1)
	{
		cin>>n;
		if(!n)
			break;
		n<<=1;
		memset(dp,-1,sizeof(dp));
		memset(a,0,sizeof(a));
		cin>>s;
		for(rgi i=1;i<=n;++i)
			cin>>a[i];
		cout<<dfs(s,1)<<endl;
	}
	return 0;
}
