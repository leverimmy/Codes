#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,d,i,count=1;
    scanf("%d",&n);
    d=10;
    while(1)
	{
	if(n/d>=1)
		{
		d=d*10;
		count++;
		}
	else
		break;
	}
    printf("%d",count);
	system("pause");
	return 0;
}
