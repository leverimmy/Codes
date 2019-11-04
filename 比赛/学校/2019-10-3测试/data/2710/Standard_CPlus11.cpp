#include<bits/stdc++.h>
#define ll long long
#define N 500010
using namespace std;
int n,m,W,L,tot,maxn;ll ans[N];
struct info{
  int x,l,r,inv,id;
  bool operator<(const info &p)const{return x<p.x;}
}s[N*4];
struct data{ll sum;int len;};
struct node{ll t1;int t2;data res;}t[N*4]; 

inline int get()
{
  char ch;int v;
  while(!isdigit(ch=getchar()));v=ch-48;
  while(isdigit(ch=getchar()))v=v*10+ch-48;
  return v;
}

class seg_tree
{
  void pushdown(int x,int l,int r)
  {
  	int mid=l+r>>1,lc=x<<1,rc=lc+1;
  	t[lc].t1+=t[x].t1;t[lc].t2+=t[x].t2;
  	t[lc].res.sum+=(mid-l+1)*t[x].t1;
  	t[lc].res.len+=(mid-l+1)*t[x].t2;
	t[rc].t1+=t[x].t1;t[rc].t2+=t[x].t2;
	t[rc].res.sum+=(r-mid)*t[x].t1;
  	t[rc].res.len+=(r-mid)*t[x].t2;
    t[x].t1=0;t[x].t2=0;
  }
  data merge(data a,data b)
  {
    return (data){a.sum+b.sum,a.len+b.len};
  }
  public:
  void modify(int x,int l,int r,int ql,int qr,ll val,int inv)
  {
    if(ql<=l&&r<=qr)
	{
	  t[x].t1+=val*inv;t[x].t2+=inv;
	  t[x].res.sum+=val*inv*(r-l+1);
	  t[x].res.len+=inv*(r-l+1);return;
	}
	int mid=l+r>>1,lc=x<<1,rc=lc+1;
	pushdown(x,l,r);
	if(ql<=mid)modify(lc,l,mid,ql,qr,val,inv);
	if(qr>mid)modify(rc,mid+1,r,ql,qr,val,inv);
	t[x].res=merge(t[lc].res,t[rc].res);
  }
  data qry(int x,int l,int r,int ql,int qr)
  {
    if(ql<=l&&r<=qr)return t[x].res;
    int mid=l+r>>1,lc=x<<1,rc=lc+1;
    pushdown(x,l,r);
    if(qr<=mid)return qry(lc,l,mid,ql,qr);
    if(ql>mid)return qry(rc,mid+1,r,ql,qr);
    return merge(qry(lc,l,mid,ql,qr),qry(rc,mid+1,r,ql,qr));
  }
}T;

int main()
{
  int X1,Y1,X2,Y2;
  scanf("%d%d%d%d",&n,&m,&W,&L);
  for(int i=1;i<=n;i++)
  {
    X1=get();Y1=get();X2=get();Y2=get();
    s[++tot]=(info){X1,Y1+1,Y2,1,0};
    s[++tot]=(info){X2,Y1+1,Y2,-1,0};
    maxn=max(maxn,Y2);
  }
  for(int i=1;i<=m;i++)
  {
  	X1=get();Y1=get();X2=get();Y2=get();
    s[++tot]=(info){X1,Y1+1,Y2,-1,i};
    s[++tot]=(info){X2,Y1+1,Y2,1,i};
  }
  sort(s+1,s+tot+1);
  for(int i=1;i<=tot;i++)
  {
    if(!s[i].id)T.modify(1,0,maxn,s[i].l,s[i].r,s[i].x,s[i].inv);
    else
    {
	  data tmp=T.qry(1,0,maxn,s[i].l,s[i].r);
	  ans[s[i].id]+=s[i].inv*((ll)tmp.len*s[i].x-tmp.sum);
	}
  }
  for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
  return 0;
} 
