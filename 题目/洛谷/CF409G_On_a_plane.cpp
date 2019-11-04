#include <cstdio>

using namespace std;

int n;
double x,y,sum=0;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf %lf",&x,&y);
		sum+=y;
	}
	printf("%f",5+sum*1.0/n);
	return 0;
}