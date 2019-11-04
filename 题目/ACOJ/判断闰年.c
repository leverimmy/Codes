#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a;
    scanf("%d",&a);
    if(((a%4==0)&&(a%100!=0))||(a%400==0))
		printf("Y");
	else
		printf("N");
	//system("pause");
	return 0;
}
