#include <stdio.h>
#include <stdlib.h>
long long int a[10000000]={0};
int main()
{
    int n,count=1,i;
    long long int max=-100000;
    scanf("%d",&n);
    for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
    for(i=0;i<n;i++)
		{
			if(a[i+1]>=a[i])	
				count++;
			else
				if(count>max)
					{
						max=count;
						count=1;
                    }
				else
					count=1;
        }
    printf("%lld",max);
	system("pause");
	return 0;
}
