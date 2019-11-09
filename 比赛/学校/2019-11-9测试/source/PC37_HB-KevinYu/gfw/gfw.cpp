#include<cstdio>
#include<cstring>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
#define ls(p) C[p].ls
#define rs(p) C[p].rs
#define mx(p) C[p].mx
#define tag(p) C[p].tag
#define l(p) C[p].l
#define r(p) C[p].r
std::vector<int>vec;
int a[200020],l[200020],v[200020],ans(0);
struct node
{
	int ls,rs;
	int mx,tag;
	int l,r;
}C[400040];
int new_node(int l,int r)
{
	static int tot(0);
	tot++;
	mx(tot)=ls(tot)=rs(tot)=tag(tot)=0;
	l(tot)=l;
	r(tot)=r;
	return tot;
}
void push_up(int p)
{
	mx(p)=std::max(mx(ls(p)),mx(rs(p)));
}
void build_tree(int &p,int l,int r)
{
	p=new_node(l,r);
	if(l==r)
	{
		mx(p)=v[l];
		return;
	}
	int mid=(l+r)/2;
	build_tree(ls(p),l,mid);
	build_tree(rs(p),mid+1,r);
	push_up(p);
}
void f(int p,int k)
{
	mx(p)+=k;
	tag(p)+=k;
}
void push_down(int p)
{
	f(ls(p),tag(p));
	f(rs(p),tag(p));
	tag(p)=0;
}
int query(int p,int lx,int rx)
{
	int l=l(p),r=r(p);
	if(l>=lx&&r<=rx)
		return mx(p);
	push_down(p);
	int mid=(l+r)/2;
	int ans(-INF);
	if(mid>=rx)
		ans=std::max(ans,query(ls(p),lx,rx));
	if(mid+1<=lx)
		ans=std::max(ans,query(rs(p),lx,rx));
	return ans;
}
void update(int p,int lx,int rx,int k)
{
	int l=l(p),r=r(p);
	if(l>=lx&&r<=rx)
	{
		f(p,k);
		return;
	}
	push_down(p);
	int mid=(l+r)/2;
	if(mid>=rx)
		update(ls(p),lx,rx,k);
	if(mid+1<=lx)
		update(rs(p),lx,rx,k);
}
int g[200020];
signed main()
{
	/*freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);*/
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&v[i]);
		vec.push_back(v[i]);
		if(v[i]>v[i-1])
			l[i]=l[i-1];
		else
			l[i]=i;
		if(!(i^1))
			l[i]=1;
		ans=std::max(ans,i-l[i]+1);
	}
	std::sort(vec.begin(),vec.end());
	vec.erase(std::unique(vec.begin(),vec.end()),vec.end());
	for(int i=1;i<=n;i++)
		v[i]=std::lower_bound(vec.begin(),vec.end(),v[i])-vec.begin()+1;
	int root;
	build_tree(root,1,n);
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[i-1])
			g[i]=g[i-1]+1;
		g[i]=std::max(g[i],query(root,i,a[i]-1));
		ans=std::max(ans,g[i]);
		update(root,a[i],n,i-l[i]+1);
	}
	return!printf("%d\n",ans);
	
	
	
	
}
