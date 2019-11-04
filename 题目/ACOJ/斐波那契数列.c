#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a=1,b=1,n,i,t;
    scanf("%d",&n);
    for(i=1;i<n;i++)
		{
        t=b;
        b=a+b;
        a=t;
        }
    printf("%d",a);
	//system("pause");
	return 0;
}
