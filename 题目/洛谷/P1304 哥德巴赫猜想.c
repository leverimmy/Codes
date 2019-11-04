#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int prime(int x)
{
	int k;
    if(x<2)
		return 0;
	else
		for(k=2;k<=sqrt(x);k++)
			if(x%k==0)
				return 0;
    return 1;
}
int main()
{
	int n,i,j;
    scanf("%d",&n);
    for(i=4;i<=n;i=i+2)
		for(j=1;j<=n/2;j++)
		{
			if((prime(j)==1)&&(prime(i-j)==1)&&(j!=0)&&(j<=i-j))
			{
                printf("%d=%d+%d\n",i,j,i-j);
                break;
                //continue;
            }
           
        }
	system("pause");
	return 0;
}
