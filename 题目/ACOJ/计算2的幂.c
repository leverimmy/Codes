#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,sum=1;
    scanf("%d",&n);
    for(i=1;i<=n;i=i+1)
		sum=sum*2;
	printf("%d",sum);
	//system("pause");
	return 0;
}
