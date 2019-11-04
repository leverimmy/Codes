#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int pingfang(int x)
{
	int i;
    for(i=0;i<=sqrt(x);i++)
		if(i*i==x)
			return 1;
	return 0;
}
int main()
{
	int n;
    int a[1000],max=-9999999,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
		scanf("%d",&a[i]);
    for(i=0;i<n;i++)
		{
			if(pingfang(a[i])==1)
				continue;
            else
				if(a[i]>max)
					max=a[i];
        }
    printf("%d",max);
	system("pause");
	return 0;
}
