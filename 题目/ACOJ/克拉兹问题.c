#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,count=0;
    scanf("%d",&n);
    while(n!=1)
		{
        if(n%2==1)
			n=3*n+1;
		else
			n=n/2;
        count++;
        }
    printf("%d",count);
	//system("pause");
	return 0;
}
