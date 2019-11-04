#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,m,i;
    int sum=0,count=0;
    int a[300000]={0};
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
		scanf("%d",&a[i]);
        if(sum+a[i]>m)
        {
			sum=0;
            count++;
        }
        sum=sum+a[i];
    }
    if(sum!=0)
		count++;
    printf("%d",count);
	system("pause");
	return 0;
}
