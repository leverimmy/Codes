#include <stdio.h>
#include <stdlib.h>
int main()
{
	int r,b,c,d,p,sum1,sum2;
    scanf("%d %d %d %d %d",&r,&b,&c,&d,&p);
    sum1=r*c+b*d;
    if(r>b)
		sum2=2*b*p+(r-b)*c;
    else
		sum2=2*r*p+(b-r)*d;
    //printf("%d %d ",sum1,sum2);
    if(sum1>sum2)
		printf("%d",sum1);
    else
		printf("%d",sum2);
	system("pause");
	return 0;
}
