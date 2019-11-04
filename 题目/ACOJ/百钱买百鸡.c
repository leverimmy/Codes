#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b;
    printf("百钱买百鸡，公鸡5元1只；母鸡3元1只；小鸡1元3只。每种鸡必须要买。求解的情况。\n");
    for(a=1;a<=20;a++)
		for(b=1;b<=33;b++)
            if((a+b+(100-a-b)==100)&&(5*a+3*b+(100-a-b)/3.0==100))
            printf("%d,%d,%d\n",a,b,(100-a-b));
	system("pause");
	return 0;
}
