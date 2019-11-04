#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
    int i;
    int a[10000],b[10000];
    scanf("%d",&n);
    for(i=0;i<=n;i++)
		scanf("%d",&a[i]);
    for(i=0;i<n;i++)
		b[i]=n-i;
    if(a[0]>1)		printf("%dx^%d",a[0],b[0]);
    if(a[0]==1)		printf("x^%d",b[0]);
    if(a[0]==-1)	printf("-x^%d",b[0]);
    if(a[0]<-1)		printf("%dx^%d",a[0],b[0]);
   // printf("%dx^%d",a[0],b[0]);
    for(i=1;i<=n-2;i++)
		{
			if(a[i]>1)		printf("+%dx^%d",a[i],b[i]);
            if(a[i]==1)		printf("+x^%d",b[i]);
            if(a[i]==0)		continue;
            if(a[i]==-1)	printf("-x^%d",b[i]);
            if(a[i]<-1)		printf("%dx^%d",a[i],b[i]);
        }
    if(a[n-1]>1)		printf("+%dx",a[n-1]);
    if(a[n-1]==1)		printf("+x");
    if(a[n-1]==-1)		printf("-x^%d",b[n-1]);
    if(a[n-1]<-1)		printf("%dx",a[n-1]);
    if(a[n]>1)			printf("+%d",a[n]);
    if(a[n]==1)			printf("+1");
    if(a[n]==-1)		printf("-1");
    if(a[n]<-1)			printf("%d",a[n]);
	system("pause");
	return 0;
}
