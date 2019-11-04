#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i;
    int a[8]={220,1184,2620,5020,6232,10744,12285,17296,63020};
    int b[8]={284,1210,2924,5564,6368,10856,14595,18416,70684};
    scanf("%d",&n);
    for(i=0;i<=9;i++)
    {
		if(a[i]>=n)
			{
				printf("%d %d",a[i],b[i]);
                system("pause");
                return 0;
            }
        if(b[i]>n)
			{
				printf("%d %d",b[i],a[i]);
                system("pause");
                return 0;
            }
    }
}
