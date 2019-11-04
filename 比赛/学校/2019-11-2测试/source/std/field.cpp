#include<bits/stdc++.h>
using namespace std;

typedef long long s64;

void exgcd(s64 a,s64 &x,s64 b,s64 &y,s64 &d)
{
	if(b==0)
	{
		d=a;x=1;y=0;
		return ;
	}
	exgcd(b,y,a%b,x,d);
	y-=a/b*x;
}

void work(s64 &l,s64 &r,s64 x,s64 d,s64 n)
{
	l=(1-x)/d;
	while(l*d<1-x)++l;
	while((l-1)*d>=1-x)--l;
	r=(n-x)/d;
	while(r*d>n-x)--r;
	while((r+1)*d<=n-x)++r;
}

int main()
{		freopen("field.in","r",stdin);
		freopen("field.out","w",stdout);
	s64 n,m,l;
	cin>>n>>m>>l;
	s64 a=n+l,b=m+l,c=m-n;//ay-bx=c
	s64 y0,x0,d;
	exgcd(a,y0,b,x0,d);//ay0+bx0=d
	if(c%d){puts("0");exit(0);}
	s64 y1=y0*s64(c/d),x1=-x0*s64(c/d);//a(y1+k b/d)-b(x1+k a/d)=c
	s64 l1,r1,l2,r2;
	work(l1,r1,y1,b/d,m/l);
	work(l2,r2,x1,a/d,n/l);
	cout<<max(0LL,min(r1,r2)-max(l1,l2)+1);
}
