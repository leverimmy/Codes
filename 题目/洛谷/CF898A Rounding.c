#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int n,k;
    scanf("%d",&n);
    k=n/10;
    k=k*10;
    if(n>k+5)
		n=k+10;
    else
		n=k;
    printf("%d",n);
	system("pause");
	return 0;
}
