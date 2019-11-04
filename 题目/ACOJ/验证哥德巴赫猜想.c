#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int prime(int x)
{
	int i;
    for(i=2;i<=sqrt(x);i++)
		if(x%i==0)	return 0;
    return 1;
}
int main()
{
	int n;
    int i,count=0;
    scanf("%d",&n);
    for(i=2;i<=n/2;i++)
		{
			if((prime(i)==1)&&(prime(n-i)==1))
				count++;
        }
    printf("%d",count);
	system("pause");
	return 0;
}
