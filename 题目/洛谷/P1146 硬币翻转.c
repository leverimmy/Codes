#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,j;
    int a[200]={0};
    scanf("%d",&n);
    printf("%d\n",n);
    for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i!=j)
					a[j]=!a[j];
            printf("%d",a[j]);
            }
            printf("\n");
        }
	system("pause");
	return 0;
}
