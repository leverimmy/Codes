#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{	
	int n,count=0,k=2,i;
    scanf("%d",&n);
    while(n>count)
    {
		for(i=2;i<=sqrt(k);i++)
			if(k%i!=0)
				count++;
    }
    printf("%d",count);
	//system("pause");
	return 0;
}
