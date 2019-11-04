#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,count0=0,count1=0;
    int a[110];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
		scanf("%d",&a[i]);
        if(a[i]%2==0)
			count0++;
        else
			count1++;
    }
    if(count1>count0)
    {
		for(i=0;i<n;i++)
			if(a[i]%2==0)
				printf("%d",i+1);
    }
    else
    {
		for(i=0;i<n;i++)
			if(a[i]%2==1)
				printf("%d",i+1);
	}
	system("pause");
	return 0;
}
