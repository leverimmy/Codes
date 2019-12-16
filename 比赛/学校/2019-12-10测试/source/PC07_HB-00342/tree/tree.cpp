#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n;
vector<int>e[200001];
int dp[200001];
int prod[200001];
void dfs(int u,int fa)
{
	dp[u]=1;
	for(int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if(to!=fa)
		{
			dfs(to,u);
			dp[u]*=dp[to];
			dp[u]%=mod;
		}
	}
	dp[u]*=(e[u].size()),dp[u]%=mod;
	dp[u]*=prod[(e[u].size()-1)],dp[u]%=mod;
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%lld%lld",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	prod[0]=1;
	for(int i=1;i<=n;i++)
		prod[i]=prod[i-1]*i%mod;
	dfs(1,0);
	printf("%lld",dp[1]*n%mod);
	return 0;
}
