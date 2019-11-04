#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,m;
    int a[110],i,j,t,money=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
		scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
	for(i=0;i<m;i++)
		money=money+a[i];
    money=-money;
    printf("%d",money);
	system("pause");
	return 0;
}
