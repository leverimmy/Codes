#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int digit[10];
int main()
{
	int i,n,x,m,j,k,l;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
		scanf("%d",&m);
        for(j=1;j<=m;j++)
        {
			x=j;
            while(x)
            {
				digit[x%10]++;
                x=x/10;
            }
        }
        for(k=0;k<9;k++)
			printf("%d ",digit[k]);
        printf("%d\n",digit[9]);
        for(l=0;l<10;l++)
			digit[l]=0;
    }
	return 0;
}
