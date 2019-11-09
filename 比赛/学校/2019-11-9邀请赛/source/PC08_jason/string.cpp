#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000001];

struct segtree1
{
	struct node
	{
		int tag,v;
	}t[1000001*4];
	node &operator[](int x){return t[x];}
	const node &operator[](int x)const{return t[x];}
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
			t[x].tag+=ind;
			t[x].v+=ind;
			return;
		}
		int mid=(st+ed)/2;
		pushdown(x);
		update(x*2,st,mid,l,r,ind);
		update(x*2+1,mid+1,ed,l,r,ind);
		t[x].v=min(t[x*2].v,t[x*2+1].v);
	}
	int query(int x,int st,int ed,int l,int r)
	{
		if(st>r||ed<l) return 999999999;
		if(st>=l&&ed<=r) return t[x].v;
		pushdown(x);
		int mid=(st+ed)/2;
		return min(query(x*2,st,mid,l,r),query(x*2+1,mid+1,ed,l,r));
	}
}t1;

struct segtree2
{
	struct node
	{
		int tag,v;
	}t[2000001*4];
	void pushdown(int x)
	{
		if(t[x].tag)
		{
			t[x*2].v=max(t[x*2].v,t[x].tag);
			t[x*2+1].v=max(t[x*2+1].v,t[x].tag);
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
		pushdown(x);
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
}t2;

vector<int>v[2000001];
const int add=1000000;
char str[1000001];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	cin>>str+1;
	int mx=0,ans=0;
	v[0+add].push_back(0);
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='(')
			t1.update(1,1,n,i,n,1);
		else
			t1.update(1,1,n,i,n,-1);
		a[i]=t1.query(1,1,n,i,i);
	
		t2.update(1,0,n+add,a[i]+add,n+add,i);
		v[a[i]+add].push_back(i);
		
		int bound=t2.query(1,0,n+add,a[i]+add-1,a[i]+add-1);
		if(!bound) bound=-1;
		
		vector<int>::iterator pre=upper_bound(v[a[i]+add].begin(),v[a[i]+add].end(),bound);
		
		if(i-(*pre)>mx)
			mx=i-(*pre),ans=0;
		if(i-(*pre)==mx) ans++;
	}
	printf("%d %d",mx,ans);
	return 0;
}