#include<cstdio>
#include<algorithm>
#define ri register int
#define rc register char
#define in inline
#define gc getchar
#define N 105
in int read()
{
	ri x=0;
	rc ch=gc();
	while(ch<'0' || ch>'9')
	{
		ch=gc();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0',ch=gc();
	}
	return x;
}
int n,w,u[N],sum,minl;
double p[N];
inline bool cmp(double A,double B)
{
	return A>B;
}
int main()
{
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	n=read(),w=read();
	for(ri i=1;i<=n;++i)
	{
		u[i]=read(),sum+=u[i];
	}
	for(ri i=1;i<=n;++i)
	{
		p[i]=u[i]*1.0/sum;
	}
	std::sort(p+1,p+1+n,cmp);
	double ans=n*1.0;
	ri place=n;
	double cnt=0,ans1,ans2;
	for(ri i=w-1;i>=1;--i)
	{
		ri j;
		ans1=0,ans2=0;
		for(j=place;j>=1;--j)
		{
			ans1=ans2,cnt+=p[j],ans2=(1-cnt)*(place-j+1);
			if(ans1>ans2)
			{
				ans2=ans1;
				break;
			}
		}
		ans-=ans2,place=j-1;
	}
	printf("%.4lf",ans);
	return 0;
}
