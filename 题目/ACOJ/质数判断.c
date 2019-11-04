#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,flag=1;
    scanf("%d",&n);
    for(i=2;i<n;i++)
		if(n%i==0)
			flag=0;
    if(flag==0)	printf("No");
    else 		printf("Yes");
	system("pause");
	return 0;
}
