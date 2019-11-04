#include <stdio.h>
#include <stdlib.h>
int zhishu(int x)
{
	int i;
    for(i=2;i<x;i++)
			if(x%i==0)
				return 0;
    return 1;
}
int main()
{	
    int sum=0,j;
	for(j=2;j<=100;j++)
		if(zhishu(j))
			sum=sum+j;
    printf("%d",sum);
	system("pause");
	return 0;
}
