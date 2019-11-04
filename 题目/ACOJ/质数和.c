#include <stdio.h>
#include <stdlib.h>
int prime(int x)
{
	int i;
    for(i=2;i<x;i++)
		if(x%i==0)	return 0;
    return 1;
}
int main()
{
	int n,i,sum=0;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
		if(prime(i)==1)
			sum=sum+i;
    printf("%d",sum);
	system("pause");
	return 0;
}
