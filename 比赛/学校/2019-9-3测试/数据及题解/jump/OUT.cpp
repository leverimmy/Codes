#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=4001;
int n,m;
int a[100005]={0},b[100005]={0};
struct node
{
	int l,r,sum,bj;
}tree[12][600005];
void Collect(int x,int rt)
{
	tree[x][rt].sum=tree[x][2*rt].sum+tree[x][2*rt+1].sum;
}
void Pass(int x,int rt)
{	
	int l=tree[x][rt].l,r=tree[x][rt].r,mid=(l+r)/2;
	if(tree[x][rt].bj)
	{
		tree[x][rt].bj=0;
		tree[x][2*rt].bj^=1;
		tree[x][2*rt].sum=mid-l+1-tree[x][2*rt].sum;
		tree[x][2*rt+1].bj^=1;
		tree[x][2*rt+1].sum=r-mid-tree[x][2*rt+1].sum;
	}
}
void Build(int rt,int l,int r,int x)
{
	tree[x][rt].l=l; tree[x][rt].r=r; tree[x][rt].bj=0;
	if(l==r){ tree[x][rt].sum=b[l]; return; }
	int mid=(l+r)/2;
	Build(2*rt,l,mid,x);
	Build(2*rt+1,mid+1,r,x);
	Collect(x,rt);
}
int Check(int x,int y)
{
	if(x&(1<<y))return 1;
	else return 0;
}
void Rev(int x,int rt,int l,int r)
{
	if(r<tree[x][rt].l||tree[x][rt].r<l)return;
	Pass(x,rt);
	if(l<=tree[x][rt].l&&tree[x][rt].r<=r)
	{
		tree[x][rt].bj^=1;
		tree[x][rt].sum=tree[x][rt].r-tree[x][rt].l+1-tree[x][rt].sum;
		return;
	}
	Rev(x,2*rt,l,r); Rev(x,2*rt+1,l,r);
	Collect(x,rt);
}
int Ask(int x,int rt,int l,int r)
{
	if(r<tree[x][rt].l||tree[x][rt].r<l)return 0;
	Pass(x,rt);
	if(l<=tree[x][rt].l&&tree[x][rt].r<=r)return tree[x][rt].sum;
	int ans=Ask(x,2*rt,l,r)+Ask(x,2*rt+1,l,r);
	Collect(x,rt);
	return ans;
}
int main()
{	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=0;i<12;i++)
	{	
		for(int j=1;j<=n;j++)
		{
			if(Check(a[j],i))b[j+1]=1;
			else b[j+1]=0;
			b[j+1]=(b[j+1]+b[j])%2;
		}
		Build(1,1,n+1,i);
	}
	int x,l,r,ans;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&l,&r);
		if(x==1)
		{
			for(int j=0;j<12;j++)
				if((Check(a[l],j)^Check(r,j)))Rev(j,1,l+1,n+1);
			a[l]=r;
		}
		else
		{	
			ans=0;
			for(int j=0;j<12;j++)
			{	
				int k=(1<<j)%mod,temp=Ask(j,1,l,r+1);
				temp=(1ll*temp*(r+1ll-l+1ll-temp))%mod;
				ans=(ans+(1ll*k*temp)%mod)%mod;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
