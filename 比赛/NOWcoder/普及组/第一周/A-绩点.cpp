#include <cstdio>
#include <algorithm>

using namespace std;

int n;
double T,S;

int main()
{
	scanf("%d",&n);
	while(n--)
	{
		double gpai;int sci;
		scanf("%lf %d",&gpai,&sci);
		T+=gpai*sci;
		S+=sci;
	}
	printf("%.1f",T*1.0/S);
	return 0;
}