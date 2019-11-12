#include<bits/stdc++.h>
using namespace std;
#define int long long
struct segtree
{
	int l,r,v;
}t[100001*120];
int seg_cnt,root;
void update(int &x,long long l,long long r,int pos,int ind)
{
	if(!x)x=++seg_cnt;
	if(l==r)
	{
		t[x].v+=ind;
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid)update(t[x].l,l,mid,pos,ind);
	else update(t[x].r,mid+1,r,pos,ind);
	t[x].v=t[t[x].l].v+t[t[x].r].v;
}
int query(int x,long long st,long long ed,long long l,long long r)
{
	if(st>r||ed<l||!x) return 0;
	if(st>=l&&ed<=r) return t[x].v;
	int mid=(st+ed)/2;
	return query(t[x].l,st,mid,l,r)+query(t[x].r,mid+1,ed,l,r);
}
const long long mx=1e12;

int n,k;
int a[100001];
long long sum[100001];
bool judge(long long x)
{
	int ans=0;
	memset(sum,0,sizeof(sum));
	
	for(int i=0;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		ans+=query(root,0,2*mx,-mx+mx,sum[i]-x+mx);
		update(root,0,2*mx,sum[i]+mx,1);
	}
	for(int i=0;i<=n;i++)
		update(root,0,2*mx,sum[i]+mx,-1);
	return ans>=k;
}
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	int l=-mx-1,r=mx+1;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(judge(mid))
			l=mid;
		else
			r=mid;
	}
	printf("%lld",l);
    return 0;
} 
/*

3 3 3
1 2 0 2
2 3 0 3
1 3 1 3

*/