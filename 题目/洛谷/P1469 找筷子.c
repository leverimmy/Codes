#include <stdio.h>
#include <stdlib.h>
long long int b[10000001]={0};
int main()
{
	long long int n,i,temp;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			b[temp]++;
        }
    for(i=0;i<=10000000;i++)
		{
			if(b[i]%2!=0)
				{
					printf("%d",i);
					break;
                }
        }
	system("pause");
	return 0;
}
