#include <stdio.h>
#include <stdlib.h>
int main()
{
	int k,n=0,i=0,sum;
    scanf("%d",&k);
    while(n<k)
    {
		n=n+i;
        i++;
    }
    i--;
    sum=i*(i+1)*(2*i+1)/6;
    k=k-n;
    //printf("%d",k);
    sum=sum+k*i;
    printf("%d",sum);
	system("pause");
	return 0;
}
