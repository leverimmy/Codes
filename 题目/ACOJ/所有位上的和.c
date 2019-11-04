#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,t,sum=0;
    scanf("%d",&n);
    while(n)
    {
		t=n%10;
        sum=sum+t;
        n=n/10;
    }
    printf("%d",sum);
	system("pause");
	return 0;
}
