#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 100010
using namespace std;
struct matrix
{
	matrix()
	{
		memset(a,0,sizeof(a));
		a[0][0]=a[1][1]=a[2][2]=1;
	}
	double a[3][3];
	void print()
	{
		int i,j;
		for(i=0;i<3;i++){for(j=0;j<3;j++)
		cout<<a[i][j]<<' ';cout<<endl;}
	}
};
matrix operator *(const matrix &x,const matrix &y)
{
	matrix ret;
	memset(ret.a,0,sizeof(ret.a));
	int i,j,k;
	for(j=0;j<3;j++)
	for(k=0;k<3;k++)
	if(y.a[k][j]!=0)
	for(i=0;i<3;i++)
	ret.a[i][j]+=x.a[i][k]*y.a[k][j];
	return ret;
}
matrix w[N<<2],chg,st;
double x[N],y[N],pi=acos(-1);
void pud(int x)
{
	w[x<<1]=w[x<<1]*w[x];
	w[x<<1|1]=w[x<<1|1]*w[x];
	w[x]=st;
}
void change(int now,int l,int r,int ll,int rr)
{
	if(l==ll&&r==rr) {w[now]=w[now]*chg;return;}
	int mid=(l+r)>>1;
	pud(now);
	if(rr<=mid) change(now<<1,l,mid,ll,rr);
	else if(ll>mid) change(now<<1|1,mid+1,r,ll,rr);
	else change(now<<1,l,mid,ll,mid),change(now<<1|1,mid+1,r,mid+1,rr);
}
void dfs(int now,int l,int r,matrix M)
{
	M=w[now]*M;
	if(l==r)
	{
		printf("%.2lf %.2lf\n",x[l]*M.a[0][0]+y[l]*M.a[1][0]+M.a[2][0],x[l]*M.a[0][1]+y[l]*M.a[1][1]+M.a[2][1]);
		return;
	}
	int mid=(l+r)>>1;
	dfs(now<<1,l,mid,M);
	dfs(now<<1|1,mid+1,r,M);
}
int main()
{	freopen("madrid.in","r",stdin);
		freopen("madrid.out","w",stdout);
	int n,m;
	int i,j,l,r;
	double p,q,a;
	char s[10];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%lf%lf",&x[i],&y[i]);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s%d%d",s,&l,&r);
		if(s[0]=='M')
		{
			scanf("%lf%lf",&p,&q);
			chg=st;chg.a[2][0]=p;chg.a[2][1]=q;
		}
		else if(s[0]=='X'){chg=st;chg.a[1][1]=-1;}
		else if(s[0]=='Y'){chg=st;chg.a[0][0]=-1;}
		else if(s[0]=='O'){chg=st;chg.a[0][0]=chg.a[1][1]=0;chg.a[1][0]=chg.a[0][1]=1;}
		else
		{
			scanf("%lf",&a);
			chg=st;
			chg.a[0][0]=chg.a[1][1]=cos(a*pi/180);
			chg.a[1][0]=-sin(a*pi/180);
			chg.a[0][1]=sin(a*pi/180);
		}
		change(1,1,n,l,r);
	}
	dfs(1,1,n,st);
}
