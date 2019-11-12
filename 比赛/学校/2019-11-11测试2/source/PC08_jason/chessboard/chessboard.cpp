#include<bits/stdc++.h>
using namespace std;
const int inf=999999999;
int n,k,m;
struct outer_segtree
{
	struct inner_segtree
	{
		pair<int,int>t[1001*4];
		void pushdown(int x)
		{
			t[x*2]=max(t[x*2],t[x]);
			t[x*2+1]=max(t[x*2+1],t[x]);
			t[x].first=-1;
		}
		
		void update(int x,int st,int ed,int l,int r,pair<int,int>ind)
		{
			if(st>r||ed<l) return;
			if(st>=l&&ed<=r) 
			{
				t[x]=max(t[x],ind);
				return;
			}
			pushdown(x);
			int mid=(st+ed)/2;
			update(x*2,st,mid,l,r,ind);
			update(x*2+1,mid+1,ed,l,r,ind);
		}
		pair<int,int>query(int x,int l,int r,int pos)
		{
			if(l==r)return t[x];
			int mid=(l+r)/2;
			pushdown(x);
			if(pos<=mid) return query(x*2,l,mid,pos);
			else return query(x*2+1,mid+1,r,pos);
		}
	}t[1001*4];

	void build(int x,int l,int r)
	{
		if(l==r) return;
		int mid=(l+r)/2;
		build(x*2,l,mid);
		build(x*2+1,mid+1,r);
	}

	void update(int x,int st,int ed,int l,int r,int yl,int yr,pair<int,int>ind)
	{
		if(st>r||ed<l)return;
		if(st>=l&&ed<=r)
		{
			t[x].update(1,1,n,yl,yr,ind);
			return;
		}
		int mid=(st+ed)/2;
		update(x*2,st,mid,l,r,yl,yr,ind);
		update(x*2+1,mid+1,ed,l,r,yl,yr,ind);
	}
	pair<int,int>query(int x,int l,int r,int posx,int posy)
	{
		if(l==r) return t[x].query(1,1,n,posy);
		int mid=(l+r)/2;
		pair<int,int>cur=t[x].query(1,1,n,posy);
		if(posx<=mid) return max(cur,query(x*2,l,mid,posx,posy));
		else return max(cur,query(x*2+1,mid+1,r,posx,posy));
	}
}t1,t2;

struct operate
{
	int x1,x2,y1,y2;
	pair<int,int>ind;
}p[100001];

char str[5];
int rem[100001];
int pre[100001],nxt[100001];
signed main()
{
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	scanf("%d%d%d",&n,&k,&m);
	int save_cnt=0;
	for(int i=1;i<=m;i++)
	{
		cin>>str;
		if(str[0]=='P')
		{
			scanf("%d%d%d%d%d",&p[i].ind.second,&p[i].x1,&p[i].y1,&p[i].x2,&p[i].y2);
			p[i].x1++,p[i].x2++,p[i].y1++,p[i].y2++;
			p[i].ind.first=i;
			pre[i]=i-1;
		}
		else if(str[0]=='S')
		{
			rem[++save_cnt]=i;
			pre[i]=i-1;
		}
		else
		{
			int x;
			scanf("%d",&x);
			pre[i]=rem[x];
		}
	}
	
	int x=m;
	vector<int>v;
	while(x)
		v.push_back(x),x=pre[x];
	reverse(v.begin(),v.end());
	
	t1.build(1,1,n);
	t2.build(1,1,n);
	t1.update(1,1,n,1,n,1,n,make_pair(0,1));
	t2.update(1,1,n,1,n,1,n,make_pair(0,1));
	for(int i=0;i<v.size();i++)
	{
		int u=v[i];
		if(p[u].x1)
		{
			if((p[u].x1+p[u].y1)%2==1)
				t1.update(1,1,n,p[u].x1,p[u].x2,p[u].y1,p[u].y2,p[u].ind);
			else
				t2.update(1,1,n,p[u].x1,p[u].x2,p[u].y1,p[u].y2,p[u].ind);
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if((i+j)%2==1)
				printf("%d ",t1.query(1,1,n,i,j).second);
			else
				printf("%d ",t2.query(1,1,n,i,j).second);
		}
		printf("\n");
	}
	return 0;
}
/*
3 4 7
PAINT 2 0 0 1 1
SAVE
PAINT 3 1 1 2 2
SAVE
PAINT 4 0 2 0 2
LOAD 2
PAINT 4 2 0 2 0
*/