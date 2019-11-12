#include<bits/stdc++.h>
using namespace std;
double psum1[500010];
double psum2[500010];
double bsum1[500010];
double bsum2[500010];
#define eps 1e-8
int n;
double t;
double eva(double x,int i)
{
	double tmp=t*(psum2[i]+bsum2[i+1]);
	double y=(tmp-(psum1[i]+psum2[i])*x)/(bsum1[i+1]+bsum2[i+1]);
	y=max(y,0.0);
	y=min(y,t);
	return max(psum1[i]*x+bsum1[i+1]*y,psum2[i]*(t-x)+bsum2[i+1]*(t-y));
}
int main()
{
	freopen("artist.in","r",stdin);
	freopen("artist.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&psum1[i],&psum2[i]);
	scanf("%lf",&t);
	for(int i=n;i>=1;i--)
	{
		bsum1[i]=bsum1[i+1]+psum1[i];
		bsum2[i]=bsum2[i+1]+psum2[i];
	}
	for(int i=1;i<=n;i++)
	{
		psum1[i]+=psum1[i-1];
		psum2[i]+=psum2[i-1];
	}
	double ans=21474836347.0;
	for(int i=0;i<=n;i++)
	{
		double l=0.0,r=t;
		while(l+eps<r)
		{
			double m1=(2*l+r)/3;
			double m2=(l+2*r)/3;
			if(eva(m1,i)<eva(m2,i))
				r=m2;
			else
				l=m1;
		}
		ans=min(ans,min(eva(0,i),min(eva(t,i),eva(l,i))));
	/*	if(fabs(ans-767290574.02)<0.01)
		{
			printf("%d %.2lf",i,r);
			return 0;
		}*/
	}
	printf("%.2lf",ans);
	return 0;
}
