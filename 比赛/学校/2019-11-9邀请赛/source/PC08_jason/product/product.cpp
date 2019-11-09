#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
struct node
{
	int t,d;
}a[100001];
int dp[201][201];
int sumt[1001];
int sumd[1001];
int dfs(int l,int r)
{
	if(dp[l][r]) return dp[l][r];
	if(l>r) return 0;
	if(l==r) return a[l].t*a[l].d;
	int ans=inf;
	for(int i=l;i<=r;i++)
	{
		int res=(sumt[i]-sumt[l-1])*(sumd[r]-sumd[i]);
		res+=a[l].d*(sumt[i]-sumt[l-1]);
		res+=dfs(l+1,i)+dfs(i+1,r);
		ans=min(ans,res);
	}
	return dp[l][r]=ans;
}
signed main()
{
	freopen("product.in","r",stdin);
	freopen("product.out","w",stdout);
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i].t,&a[i].d),sumt[i]=sumt[i-1]+a[i].t,sumd[i]=sumd[i-1]+a[i].d;
	printf("%lld",dfs(1,n));
	return 0;
}
/*
4
1 4
3 2
5 2
2 1
*/