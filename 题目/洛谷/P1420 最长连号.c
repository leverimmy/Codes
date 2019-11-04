#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[100000]={0};
    int n,count=1,i;
    int max=-1000;
    scanf("%d",&n);
    for(i=0;i<n;i++)
		scanf("%d",&a[i]);
    for(i=0;i<n;i++)
		{
			if(a[i+1]==a[i]+1)	
				count++;
			else
				if(count>max)
					{
						max=count;
						count=1;
                    }
        }
    printf("%d",max);
	system("pause");
	return 0;
}
