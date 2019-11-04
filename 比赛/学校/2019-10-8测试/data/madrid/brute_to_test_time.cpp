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
int main()
{
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
			for(i=l;i<=r;i++);
		}
		else if(s[0]=='X')for(i=l;i<=r;i++);
		else if(s[0]=='Y')for(i=l;i<=r;i++);
		else if(s[0]=='O')for(i=l;i<=r;i++);
		else
		{
			scanf("%lf",&a);
			for(i=l;i<=r;i++);
		}
	}
}