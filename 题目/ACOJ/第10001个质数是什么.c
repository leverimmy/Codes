#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int prime(int x)
{
	int i;
    for(i=2;i<x;i++)
		if(x%i==0)	return 0;
    return 1;
}
int main()
{
	int n,i=2,num=0,p;
    scanf("%d",&n);
    while(num<n)
	{
		if(prime(i)==1)	
			num++;
        p=i;
        i++;
    }
    printf("%d",p);
	system("pause");
	return 0;
}
