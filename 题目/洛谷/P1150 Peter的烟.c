#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,k;
	int sum=0,di=0;
	scanf("%d %d",&n,&k);
	di=n;
	sum=sum+n;
	while(di>=k)
	{
		di=di-k;
		di++;
		sum++;
	}
	printf("%d",sum);
	getchar();getchar();
	return 0;
}
