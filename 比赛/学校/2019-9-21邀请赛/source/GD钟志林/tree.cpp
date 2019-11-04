#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int n,m,u,v,c,t[500005],ans,last[500005],p[5000005];
bool qw[500005]={false};
struct zz
{
	int bg,to,l,next;
}a[1000005];
void add(int x,int y,int z)
{
	ans++;a[ans].bg=x;a[ans].to=y;a[ans].l=z;
	a[ans].next=last[x];last[x]=ans;
}
void SPFA()
{
	int hd=1,tl=1;
	p[hd]=1;
	while (hd<=tl)
	  {
	  	int x=p[hd];
	  	for (int i=last[x];i;i=a[i].next)
	  	  {
	  	  	int y=a[i].to,u;
	  	  	if (y==1) continue;
	  	  	if (x!=1) u=max(t[x],a[i].l);
	  	  	  else u=a[i].l;
	  	  	if (u<t[y])
	  	  	  {
	  	  	  	t[y]=u;
	  	  	  	if (!qw[y]) tl++,qw[y]=true,p[tl]=y;
	  	  	  }
	  	  }
	  	qw[hd]=false;
	  	hd++;
	  }
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	  {
	  	scanf("%d%d%d",&u,&v,&c);
	  	add(u,v,c);
	  	add(v,u,c);
	  }
	for (int i=1;i<=n;i++) t[i]=999999;
	SPFA();
	long long sum=0;
	for (int i=2;i<=n;i++) sum+=t[i];
	cout<<sum;
	return 0;
}
