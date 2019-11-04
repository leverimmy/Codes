#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	int n,i,j,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(t=1;t<i;t++)
			printf(" ");
		for(j=1;j<=2*n+1-2*i;j++)
			printf("*");
		printf("\n");
	}
	return 0;
}