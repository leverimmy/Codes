#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[1001]={0};
    int i,t,n,count=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
		{
			scanf("%d",&t);
			a[t]++;
        }
    //printf("%d",t);
    for(i=1;i<=1000;i++)
		if(a[i]!=0)
			count++;
    printf("%d\n",count);
    for(i=1;i<=1000;i++)
		if(a[i]!=0)
			printf("%d ",i);
	//system("pause");
	return 0;
}
