#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,j;
    int a[8][8];
    for(i=1;i<7;i++)
		for(j=0;j<i;j++)
			if(i==j) a[i][j]=1;
            for(i=0;i<7;i++)
				a[i][0]=1;
            a[i][j]=a[i-1][j-1]+a[i-1][j];
    for(i=0;i<7;i++)
		{
			for(j=0;j<i;j++)
				printf("%5d",a[i][j]);
			printf("\n");
        }
	system("pause");
	return 0;
}
