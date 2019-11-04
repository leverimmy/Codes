#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<climits>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<complex>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f
#define ll long long
#define ls(p) t[p].ls
#define rs(p) t[p].rs
#define fa(p) t[p].fa
#define rnd(p) t[p].rnd
#define size(p) t[p].size
#define val(p) t[p].val
#define mid ((l+r)>>1)
struct node
{
	int ls,rs,size,rnd,val;
}t[1000010];
int cnt,root;
void push_up(int p)
{
	size(p)=size(ls(p))+size(rs(p))+1;
}
void new_node(int &k,int x)
{
	k=++cnt;
	val(k)=x;
	size(k)=1;
	rnd(k)=rand();
	ls(k)=rs(k)=0;
	k=cnt;
}
int merge(int x,int y)
{
	if(!x||!y)
		return x|y;
	if(rnd(x)>rnd(y))
	{
		rs(x)=merge(rs(x),y);
		push_up(x);
		return x;
	}
	else
	{
		ls(y)=merge(x,ls(y));
		push_up(y);
		return y;
	}
}
void split(int p,int k,int &x,int &y)
{
	if(!p)
	{
		x=y=0;
		return;
	}
	if(val(p)<k)
	{
		x=p;
		split(rs(x),k,rs(x),y);
		push_up(x);
	}
	else
	{
		y=p;
		split(ls(y),k,x,ls(y));
		push_up(y);
	}
}
void pop(int &root,int w)
{
	int x=0,y=0,z=0;
	split(root,w,x,z);
	split(x,w-1,x,y);
	y=merge(ls(y),rs(y));
	root=merge(merge(x,y),z);
}
void push(int &root,int w)
{
	int x=0,y=0,z=0;
	split(root,w,x,y);
	new_node(z,w);
	root=merge(merge(x,z),y);
}
int atrank(int p,int w)
{
	if(w==size(ls(p))+1)
		return val(p);
	else if(w<=size(ls(p)))
		return atrank(ls(p),w);
	else
		return atrank(rs(p),w-size(ls(p))-1);
}
int rnk(int &root,int w)
{
	int x,y;
	split(root,w-1,x,y);
	int ans=size(x)+1;
	root=merge(x,y);
	return ans;
}
int pre(int &root,int w)
{
	int x,y,k,ans;
	split(root,w-1,x,y);
	if(!x)
		return -INF;
	k=size(x);
	ans=atrank(x,k);
	root=merge(x,y);
	return ans;
}
int next(int &root,int w)
{
	int x,y,ans;
	split(root,w,x,y);
	if(!y)
		return INF;
	else 
		ans=atrank(y,1);
	root=merge(x,y);
	return ans;
}
signed main()
{
	freopen("unhappy.in","r",stdin);
	freopen("unhappy.out","w",stdout);
	int m,ls,dt(0),ans(0);
	scanf("%d%d",&m,&ls);
	while(m--)
	{
		char opt;
		std::cin>>opt;
		int k;
		scanf("%d",&k);
		if(opt=='I')
		{
			k-=dt;
			if(k<ls)
				continue;
			if(!root)
			{
				new_node(root,k);
				continue;
			}
			int p;
			new_node(p,k);
			root=merge(root,p);
		}
		if(opt=='A')
		{
			ls-=k;
			dt+=k;
		}
		if(opt=='S')
		{
			ls+=k;
			dt-=k;
			int x;
			split(root,ls,x,root);
			ans+=size(x);
		}
		if(opt=='F')
		{
			if(!root||size(root)<k)
				puts("-1");
			else
				printf("%d\n",atrank(root,size(root)-k+1)+dt);
		}
	}
	return!printf("%d\n",ans);
}
