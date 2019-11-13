#include<bits/stdc++.h>
using namespace std;
struct segtree
{
	int v,tag;
}t[500001*4];
void pushdown(int x)
{
	if(t[x].tag)
	{
		t[x*2].v+=t[x].tag;
		t[x*2+1].v+=t[x].tag;
		t[x*2].tag+=t[x].tag;
		t[x*2+1].tag+=t[x].tag;
		t[x].tag=0;
	}
}
void update(int x,int st,int ed,int l,int r,int ind)
{
	if(st>r||ed<l) return;
	if(st>=l&&ed<=r)
	{
		t[x].tag+=ind,t[x].v+=ind;
		return;
	}
	int mid=(st+ed)/2;
	pushdown(x);
	update(x*2,st,mid,l,r,ind);
	update(x*2+1,mid+1,ed,l,r,ind);
}
int query(int x,int l,int r,int pos)
{
	if(l==r){return t[x].v;}
	pushdown(x);
	int mid=(l+r)/2;
	if(pos<=mid) return query(x*2,l,mid,pos);
	else return query(x*2+1,mid+1,r,pos);
}
signed main()
{
	freopen("clean.in","r",stdin);
	freopen("clean.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		update(1,1,n,u,v,1);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(query(1,1,n,i)==0)
			ans++;
	printf("%d",ans);
    return 0;
} 
