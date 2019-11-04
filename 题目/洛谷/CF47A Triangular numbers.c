#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,n,flag=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
		if(i*(i+1)/2==n)
			flag=1;
    if(flag==1)
		printf("YES");
    else
		printf("NO");
	system("pause");
	return 0;
}
