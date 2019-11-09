#include<bits/stdc++.h>
using namespace std;
vector<int>prime;
bool noprime[10000001];
int mnfac[10000001];
void primelist(int n)
{
	noprime[1]=0;
	for(int i=2;i<=n;i++)
	{
		if(!noprime[i])
			prime.push_back(i),mnfac[i]=i;
		for(int j=0;j<prime.size()&&prime[j]*i<=n;j++)
		{
			noprime[prime[j]*i]=1;
			mnfac[prime[j]*i]=prime[j];
			if(i%prime[j]==0)
				break;
		}
	}
}
int a[100001];
int l[100001],r[100001];
map<int,int>mp;
int fa[100001];
int dfs(int pl,int pr)
{
	for(int i=pl;i<=pr;i++)
		if(l[i]<pl&&r[i]>pr)
		{
			fa[dfs(pl,i-1)]=i;
			fa[dfs(i+1,pr)]=i;
			return i;
		}
}
signed main()
{
	primelist(10000000);
	
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	mp.clear();
	for(int i=1;i<=n;i++)
	{
		int u=a[i];
		while(u!=1)
		{
			int x=mnfac[u];
			if(mp[x]) l[i]=max(l[i],mp[x]);
			mp[x]=i;
			while(u!=1&&u%x==0)
				u/=x;
		}
	}
	mp.clear();
	memset(r,0x3f,sizeof(r));
	for(int i=n;i>=1;i--)
	{
		int u=a[i];
		while(u!=1)
		{
			int x=mnfac[u];
			if(mp[x]) r[i]=min(r[i],mp[x]);
			mp[x]=i;
			while(u!=1&&u%x==0)
				u/=x;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!l[i]) l[i]=0;
		if(r[i]>999999999) r[i]=n+1;
	}
	dfs(1,n);
	for(int i=1;i<=n;i++)
		printf("%d ",fa[i]);
	return 0;
}