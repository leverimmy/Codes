#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[100],n,biggest=0,i;
    scanf("%d",&n);
    for(i=0;i<=100;i=i+1)
		a[i]=0;
    for(i=0;i<=n;i=i+1)
		scanf("%d",&a[i]);
    for(i=0;i<=n;i=i+1)
		{
        if(a[i]>=biggest)
			biggest=a[i];
        }
    printf("%d",biggest);
	//system("pause");
	return 0;
}
