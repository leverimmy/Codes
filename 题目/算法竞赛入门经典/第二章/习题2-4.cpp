#include <cstdio>
#include <cstdlib>

using namespace std;

int n,m;

double sum(int x)
{
	double r=0;
	for(int i=1;i<=x;i++)
		r+=1.0/i/i;
	return r;
}

int main()
{
	while(scanf("%d %d",&n,&m)&&(n||m))
	{
		double ans;
		ans=sum(m)-sum(n-1);
		printf("%.5f\n",ans);
	}
	return 0;
}