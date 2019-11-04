#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b,c,d,e,count=0;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    while(a>=1 && b>=1 && c>=2 && d>=7 && e>=4)
    {
		a=a-1;
        b=b-1;
        c=c-2;
        d=d-7;
        e=e-4;
        count++;
    }
    printf("%d",count);
	system("pause");
	return 0;
}
