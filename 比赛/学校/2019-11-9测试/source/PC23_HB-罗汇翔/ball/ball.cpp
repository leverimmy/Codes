#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
struct ball
{
	double x;
	double r;
	int num;
	double ans;
};
ball f[200010];
bool cmp1(const ball &a,const ball &b)
{
	return a.x<b.x;
}
bool cmp2(const ball &a,const ball &b)
{
	return a.num<b.num;
}
double dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double ans;
double l,r,mid;
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i].x>>f[i].r;
		f[i].num=i;
	}
	sort(f+1,f+n+1,cmp1);
	for(int i=1;i<=n;i++)
	{
		f[i].ans=f[i].r;
		for(int j=i-1;j>=1;j--)
		{
			l=0;r=f[i].r;
			while(r-l>0.001)
			{
				mid=(l+r)/2;
				if(dis(f[i].x,mid,f[j].x,f[j].ans)-f[j].ans-mid>=0)
				{
					ans=mid;
					l=mid;
				}
				else r=mid;
			}
            f[i].ans=min(f[i].ans,ans);
		}
	}
	sort(f+1,f+n+1,cmp2);
	for(int i=1;i<=n;i++)
	{
		printf("%.3lf\n",f[i].ans);
	}
	return 0;
}

