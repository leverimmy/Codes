#include <stdio.h>
#include <stdlib.h>
int main()
{	int a,b,t;
	scanf("%d%d",&a,&b);
    t=b;
    b=a;
    a=t;
	printf("%d %d",a,b);
	system("pause");
	return 0;
}
