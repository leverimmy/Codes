#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,num=0;
    scanf("%d",&n);
    if(n==0)
		printf("1");
    else
		{
			while(n)
			{
				n=n/10;
				num++;
			}
			printf("%d",num);
        }
	system("pause");
	return 0;
}
