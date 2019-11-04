#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int T,k;
int l[100010],r[100010];
int rm;
long long num[100010];
long long ans[100010];

int main()
{
	freopen("pool.in","r",stdin);
	freopen("pool.out","w",stdout);
	scanf("%d%d",&T,&k);
	for(int i=1;i<=T;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		rm=max(r[i],rm);
	}
	num[0]=ans[0]=1;
	for(int i=1;i<=k-1;i++)
		num[i]=1,ans[i]=num[i]+ans[i-1];
	
	num[k]=2;
	ans[k]=ans[k-1]+num[k];
	for(int i=k+1;i<=2*k-1;i++)
	{
		num[i]=(ans[i-k]+1)%mod;
		ans[i]=(ans[i-1]+num[i])%mod;
	}
	for(int i=2*k;i<=rm;i++)
	{
		num[i]=(ans[i-k]-(i-2*k+1)+1)%mod;
		ans[i]=(ans[i-1]+num[i])%mod;
	}
	for(int i=1;i<=T;i++)
	{
		printf("%d\n",((ans[r[i]]-ans[l[i]-1])%mod+mod)%mod);
	}
	return 0;
}
