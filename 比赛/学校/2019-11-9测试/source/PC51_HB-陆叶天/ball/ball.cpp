#include <cstdio>
#include <algorithm>
using namespace std;
double x[2009],r[2009];
double a[2009];
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&x[i],&r[i]);
	}
	a[1]=r[1]*1.00000;
	printf("%.3lf\n",a[1]);
	for(int i=2;i<=n;i++)
	{
		double h=999999999.00000;
		for(int j=1;j<i;j++)
		{
			h=min(h,(x[j]-x[i])*(x[j]-x[i])*1.00000/(4*a[j])*1.0000);
		}
		printf("%.3lf\n",min(h,r[i]));
		a[i]=min(h,r[i]);
	}
	return 0;
}
