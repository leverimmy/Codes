#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[110]={0,1,2,4,6};
    int n,i;
    scanf("%d",&n);
    for(i=5;i<110;i++)
    {
		a[i]=2*a[i-1]-2*a[i-3]+a[i-4];
    }
    printf("%d",a[n]);
	system("pause");
	return 0;
}
