#include <stdio.h>
#include <stdlib.h>
int main()
{
	int k,i;
    scanf("%d",&k);
    for(i=1;i<=sqrt(k);i++)
		printf("%d ",i*i);
	system("pause");
	return 0;
}
