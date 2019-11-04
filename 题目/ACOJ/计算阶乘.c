#include <stdio.h>
#include <stdlib.h>
long long int jiecheng(int x)
{	
    long long int i,sum=1;
    for(i=1;i<=x;i++)
		sum=sum*i;
    return sum;
}
int main()
{
	printf("%lld\n",jiecheng(5)+jiecheng(7)+jiecheng(4));
    system("pause");
	return 0;
}
