#include <stdio.h>
#include <stdlib.h>
unsigned long long int sum1,sum2,sum3,sum;
int main()
{
	int t1,t2,t3;
    int r1,r2,r3;
    int v;
    scanf("%d:%d:%d",&t1,&t2,&t3);
    scanf("%d:%d:%d",&r1,&r2,&r3);
    scanf("%d",&v);
    sum1=3600*(r1-t1);
    sum2=60*(r2-t2);
    sum3=r3-t3;
    sum=sum1+sum2+sum3;
    printf("%lu",sum*v);
	system("pause");
	return 0;
}
