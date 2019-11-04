#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,count=0;
    int a[100000];
    int i,j,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
		scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
				{
					t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                    count++;
                }
    printf("%d",count);
	system("pause");
	return 0;
}
