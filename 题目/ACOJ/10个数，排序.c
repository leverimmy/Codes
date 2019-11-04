#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[10],n,i,j,t;
    for(n=0;n<10;n++)
		scanf("%d",&a[n]);
    for(i=0;i<9;i++)
		for(j=0;j<i;j++)
            if(a[j]>a[j+1])
            {
			 t=a[j];
             a[j]=a[j+1];
             a[j+1]=t;
            }
    for(n=0;n<9;n++)
		printf("%d ",a[n]);
	system("pause");
	return 0;
}
