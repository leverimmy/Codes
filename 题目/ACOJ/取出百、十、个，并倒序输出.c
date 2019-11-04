#include <stdio.h>
#include <stdlib.h>
int main()
{	int n,a,b,c;
	scanf("%d",&n);
    a=n/100;
    b=(n/10)%10;
    c=n%10;
	printf("%d%d%d",c,b,a);
	system("pause");
	return 0;
}
