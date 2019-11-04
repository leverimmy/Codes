#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int a,b;
    int k,r;
    scanf("%d",&k);
    a=1;
    b=1;
    r=a+b;
    while(r<=k)
    {
		a=b;
        b=r;
        r=a+b;
    }
    printf("m=%d\n",a);
    printf("n=%d",b);
	system("pause");
	return 0;
}
