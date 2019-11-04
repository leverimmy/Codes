#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
    int i,j;
    int count=0,t;
    int a[100];	
    scanf("%d",&n);
    for(i=0;i<100;i++)
		a[i]=0;
    for(i=1;i<n;i++)
		scanf("%d",&a[i]);
    for(i=1;i<=n-1;i++)
		for(j=1;j<=i-1;j++)
			if(a[j]>a[j+1]) {t=a[j];a[j]=a[j+1];a[j+1]=t;}
    for(i=1;i<=n;i++)
		if(a[i]==a[i+1]) continue;
			count++;
    printf("%d\n",count);
    for(i=1;i<=n;i++)
		if(a[i]==a[i+1]) continue;
			printf("%d ",a[i]);
	system("pause");
	return 0;
}
