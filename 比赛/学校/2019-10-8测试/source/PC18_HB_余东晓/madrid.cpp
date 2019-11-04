/*
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cassert>
#include<cstring>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<stack>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
#define pi 3.1415926535
// #define ls(p) tr[p].ls
// #define rs(p) tr[p].rs
// #define l(p) tr[p].l
// #define r(p) tr[p].r
// #define tag(p) tr[p].tag
// #define val(p) tr[p].val
// #define add(p) tr[p].add
struct mat
{
	double a[2][2];
	mat(){}
	mat(double a1,double a2,double a3,double a4)
	{
		a[0][0]=a1;
		a[0][1]=a2;
		a[1][0]=a3;
		a[1][1]=a4;
	}
};
mat I(mat(1,0,0,1));
mat R(mat(0,0,0,0));
mat operator *(mat a,mat b)
{
	int n=2;
	mat ans(mat(0,0,0,0));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				ans.a[i-1][j-1]+=(a.a[i-1][k-1]*b.a[k-1][j-1]);
	return ans;
}
void operator *=(mat &x,mat y)
{
	x=x*y;
}
mat fastpow(mat x,int y)
{
	mat ans(I);
	while(y)
	{
		if(y&1)
			ans*=x;
		x*=x;
		y>>=1;
	}
	return ans;
}
mat operator +(mat x,mat y)
{
	int n=2;
	mat res(mat(0,0,0,0));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			res.a[i-1][j-1]+=(x.a[i-1][j-1]+y.a[i-1][j-1]);
	return res;
}
bool operator ==(mat x,mat y)
{
	int n=2;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(x.a[i-1][j-1]!=y.a[i-1][j-1])
				return 0;
	return 1;
}
void operator +=(mat &x,mat y)
{
	x=x+y;
}
mat spin(double x)
{
	double k=(x/360.0)*2*pi;
	return mat(cos(k),sin(k),-sin(k),cos(k));
}
// mat vec(double x,double y)
// {
	// return mat(x,y,0,0);
// }
// mat mum(double x,double y)
// {
	// return mat(x,0,0,y);
// }
// mat swm()
// {
	// return mat(0,1,1,0);
// }
// struct node
// {
	// int ls,rs,l,r;
	// mat val,tag,add;
// }tr[1000010];
// int tot(0);
// void build_tree(int l,int r,int &p)
// {
	// p=++tot;
	// int mid=(l+r)/2;
	// l(p)=l;
	// r(p)=r;
	// tag(p)=I;
	// add(p)=R;
	// val(p)=R;
	// if(l==r)
	// {
		// val(p)=vec(xv[l],yv[l]);
		// l(p)=r(p)=l;
		// return;
	// }
	// build_tree(l,mid,ls(p));
	// build_tree(mid+1,r,rs(p));
// }
// void f(int p,mat k)
// {
	// if(l(p)==r(p))
		// val(p)*=k;
	// tag(p)*=k;
// }
// void g(int p,mat k)
// {
	// if(l(p)==r(p))
		// val(p)+=k;
	// tag(p)+=k;
// }
// void push_down(int p)
// {
	// if(!(tag(p)==I))
	// {
		// if(ls(p))
			// f(ls(p),tag(p));
		// if(rs(p))
			// f(rs(p),tag(p));
		// tag(p)=I;
	// }
	// if(!(add(p)==R))
	// {
		// if(ls(p))
			// g(ls(p),add(p));
		// if(rs(p))
			// g(rs(p),add(p));
		// add(p)=R;
	// }
// }
// mat query(int ql,int qr,int p)
// {
	// int l=l(p);
	// int r=r(p);
	// if(l>=ql&&r<=qr)
		// return val(p);
	// push_down(p);
	// mat ans(mat(0,0,0,0));
	// int mid=(l+r)/2;
	// if(mid>=ql)
		// ans+=query(ql,qr,ls(p));
	// if(mid+1<=qr)
		// ans+=query(ql,qr,rs(p));
	// push_up(p);
	// return ans;
// }
// void mul(int ul,int ur,int p,mat k)
// {
	// int l=l(p),r=r(p);
	// if(l>=ul&&r<=ur)
	// {
		// f(p,k);
		// return;
	// }
	// push_down(p);
	// int mid=(l+r)/2;
	// if(mid>=ul)
		// mul(ul,ur,ls(p),k);
	// if(mid+1<=ur)
		// mul(ul,ur,rs(p),k);
// }
// void upd(int ul,int ur,int p,mat k)
// {
	// int l=l(p),r=r(p);
	// if(l>=ul&&r<=ur)
	// {
		// g(p,k);
		// return;
	// }
	// push_down(p);
	// int mid=(l+r)/2;
	// if(mid>=ul)
		// upd(ul,ur,ls(p),k);
	// if(mid+1<=ur)
		// upd(ul,ur,rs(p),k);
// }
// struct point
// {
	// double x,y;
	// point(){}
	// point(int x,int y):x(x),y(y){}
// }v[100010];
// void conv(point &x,mat y)
// {
	// x.x=y.a[0][0];
	// x.y=y.a[0][1];
// }
// signed main()
// {
	// freopen("madrid.in","r",stdin);
	// freopen("madrid.out","w",stdout);
	// int n;
	// scanf("%d",&n);
	// for(int i=1;i<=n;i++)
		// scanf("%lf%lf",&xv[i],&yv[i]);
	// int rt;
	// build_tree(1,n,rt);
	// int m;
	// scanf("%d",&m);
	// while(m--)
	// {
		// char opt[2];
		// scanf("%s",opt);
		// if(opt[0]=='M')
		// {
			// int l,r;
			// double p,q;
			// scanf("%d%d%lf%lf",&l,&r,&p,&q);
			// upd(l,r,rt,adm(p,q));
		// }
		// if(opt[0]=='X')
		// {
			// int l,r;
			// scanf("%d%d",&l,&r);
			// mul(l,r,rt,mum(1,-1));
		// }
		// if(opt[0]=='Y')
		// {
			// int l,r;
			// scanf("%d%d",&l,&r);
			// mul(l,r,rt,mum(-1,1));
		// }
		// if(opt[0]=='O')
		// {
			// int l,r;
			// scanf("%d%d",&l,&r);
			// mul(l,r,rt,swm());
		// }
		// if(opt[0]=='R')
		// {
			// int l,r;
			// double x;
			// scanf("%d%d%lf",&l,&r,&x);
			// mul(l,r,rt,spin(x));
		// }
	// }
	// for(int i=1;i<=tot;i++)
		// push_down(i);
	// for(int i=1;i<=tot;i++)
		// if(l(i)==r(i))
			// conv(v[l(i)],val(i));
	// for(int i=1;i<=n;i++)
		// printf("%.2lf %.2lf\n",v[i].x,v[i].y);
	// return 0;
// }
#define x(p) a[p].x
#define y(p) a[p].y
#define S 320
#define l(p) a[p].l
#define r(p) a[p].r
#define tagm(p) a[p].tagm
#define taga(p) a[p].taga
struct node
{
	int l,r;
	mat tagm,taga;
}a[320];
int bl[100010];
void push_down(int p,bool f)
{
	if(!f)
	{
		for(int i=l(p);i<=r(p);i++)
			
	}
	if(f)
	{
		for(int i=l(p);i<=r(p);i++)
			
	}
}
signed main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&x(p),&y(p));
	int m=n/S;
	for(int i=1;i<=n;i++)
	{
		if(i%len==0)
			bl[i]=i/S;
		else
			bl[i]=i/S+1;
	}
	for(int i=1;i<=m;i++)
	{
		l(i)=(i-1)*S+1;
		r(i)=i*S;
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		char opt[2];
		scanf("%s",opt);
		if(opt[0]=='M')
		{
			int l,r;
			double p,q;
			scanf("%d%d%lf%lf",&l,&r,&p,&q);
			int lb=bl[l],rb=bl[r];
			for(int i=lb;i<=rb;i++)
				push_down(i);
			if(lb==rb)
			{
				for(int i=l;i<=r;i++)
					
			}
			
		}
		if(opt[0]=='X')
		{
			int l,r;
			scanf("%d%d",&l,&r);
		}
		if(opt[0]=='Y')
		{
			int l,r;
			scanf("%d%d",&l,&r);
		}
		if(opt[0]=='O')
		{
			int l,r;
			scanf("%d%d",&l,&r);
		}
		if(opt[0]=='R')
		{
			int l,r;
			double x;
			scanf("%d%d%lf",&l,&r,&x);
		}
	}
}
*/


#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cassert>
#include<cstring>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<stack>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
#define pi 3.1415926535
struct node 
{
	double x,y;
}a[1000001];
int n,m;
signed main() 
{
	freopen("madrid.in","r",stdin);
	freopen("madrid.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	scanf("%d",&m);
	while(m--) 
	{
		char opt;
		std::cin>>opt;
		int l,r;
		scanf("%d%d",&l,&r);
		if(opt=='M') 
		{
			double p,q;
			scanf("%lf%lf",&p,&q);
			for(int i=l;i<=r;i++) 
			{
				a[i].x+=p;
				a[i].y+=q;
			}
		}
		if(opt=='X')
			for(int i=l;i<=r;i++)
				a[i].y=-a[i].y;
		if(opt=='Y')
			for(int i=l;i<=r;i++)
				a[i].x=-a[i].x;
		if(opt=='O')
			for(int i=l;i<=r;i++)
				std::swap(a[i].x,a[i].y);
		if(opt=='R')
		{
			double p;
			scanf("%lf",&p);
			p=p/(double)180*pi;
			for(int i=l;i<=r;i++) 
			{
				double xx=a[i].x,yy=a[i].y;
				a[i].x=cos(p)*xx-sin(p)*yy;
				a[i].y=sin(p)*xx+cos(p)*yy;
			}
		}
	}
	for(int i=1;i<=n;i++)
		printf("%.2f %.2f\n",a[i].x,a[i].y);
	return 0;
}
