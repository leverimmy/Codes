#include <stdio.h>
#include <stdlib.h>
int a[1000];
int main()
{
	int n,i,j,flag=0;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
		a[1]=i;
        for(j=1;j<n;j++)
        {
			a[a[j]]=n-j+1;
        }
        if(a[a[n]]==n-n+1)
			flag=1;
        if(flag)
			{
				for(j=1;j<=n;j++)
					printf("%d\n",a[j]);
                break;
            }
    }
    if(flag==0)
		printf("0");
	system("pause");
	return 0;
}
