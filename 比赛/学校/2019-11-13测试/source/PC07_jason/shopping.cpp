#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int l,r;
}t[1000001];
bool cmp(node a,node b)
{
	if(a.l!=b.l)return a.l<b.l;
	return a.r>b.r;
}
int n,m;
int a[5001],sum[5001];
int dp[5001];
int l[5001];
signed main()
{
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=m;i++)
		scanf("%lld%lld",&t[i].l,&t[i].r);
	sort(t+1,t+m+1,cmp);
	int far=0;
	for(int i=1;i<=m;i++)
    {
		if(t[i].r<=far)
			continue;
		far=max(far,t[i].r);
		l[t[i].r]=t[i].l;
	}
	int mn=999999999;
	far=n+1;
	for(int i=n;i>=1;i--)
	{
		if(l[i])
			far=min(far,l[i]);
		if(i<far) continue;
		l[i]=far;
	}
	for(int i=1;i<=n;i++)
		if(l[i])
		{
			for(int j=1;j<=i;j++)
				if(j<l[i])
					dp[i]=max(dp[i],dp[j-1]+(sum[i]-sum[l[i]-1])*(sum[i]-sum[l[i]-1]));
				else
					dp[i]=max(dp[i],dp[j-1]+(sum[i]-sum[j-1])*(sum[i]-sum[j-1]));
		}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	printf("%lld",ans);
	return 0;
} 
