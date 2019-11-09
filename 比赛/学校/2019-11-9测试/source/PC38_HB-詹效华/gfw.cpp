#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
	int tag,v;
}t[200001*4];
void pushdown(int x)
{
	if(t[x].tag)
	{
		t[x*2].v=max(t[x*2].tag,t[x].tag);
		t[x*2+1].v=max(t[x*2+1].tag,t[x].tag);
		t[x*2].tag=max(t[x*2].tag,t[x].tag);
		t[x*2+1].tag=max(t[x*2+1].tag,t[x].tag);
		t[x].tag=0;
	}
}
void update(int x,int st,int ed,int l,int r,int ind)
{
	if(st>r||ed<l) return;
	if(st>=l&&ed<=r)
	{
		t[x].tag=max(t[x].tag,ind);
		t[x].v=max(t[x].v,ind);
		return;
	}
	int mid=(st+ed)/2;
	update(x*2,st,mid,l,r,ind);
	update(x*2+1,mid+1,ed,l,r,ind);
	t[x].v=max(t[x*2].v,t[x*2+1].v);
}
int query(int x,int st,int ed,int l,int r)
{
	if(st>r||ed<l) return 0;
	if(st>=l&&ed<=r) return t[x].v;
	pushdown(x);
	int mid=(st+ed)/2;
	return max(query(x*2,st,mid,l,r),query(x*2+1,mid+1,ed,l,r));
}
int n,ans;
int a[200001],l[200001];
int dp[200001];
vector<int>v;
signed main()
{
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		v.push_back(a[i]);
		if(a[i]>a[i-1])
			l[i]=l[i-1];
		else
			l[i]=i;
		if(i==1) l[i]=1;
		ans=max(ans,i-l[i]+1);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[i-1])
			dp[i]=dp[i-1]+1;
		dp[i]=max(dp[i],query(1,1,n,1,a[i]-1)+1);
		ans=max(ans,dp[i]);
		update(1,1,n,a[i],n,i-l[i]+1);
	}
	printf("%d",ans);
}
/*
9 
5 3 4 9 2 8 6 7 1
*/