#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,sum=1,i;
    int k[200010];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
		scanf("%d",&k[i]);
        if(k[i]==8)
			sum=sum*2;
	}
    printf("%d",sum);
	system("pause");
	return 0;
}
