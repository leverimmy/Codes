#include <stdio.h>
#include <stdlib.h>
int main()
{	int a,b,c,d,e,f;
	printf("请输入两个数字，中间用逗号隔开。\n");
	scanf("%d,%d",&a,&b);
    printf("您输入的是%d和%d\n",a,b);
    c=a+b;
    printf("它们的和是%d+%d=%d\n",a,b,c);
    d=a-b;
    printf("它们的差是%d-%d=%d\n",a,b,d);
    e=a*b;
    printf("它们的积是%d*%d=%d\n",a,b,e);
    f=a/b;
    printf("它们的商是（仅保留个位数）%d/%d=%d\n",a,b,f);
    system("pause");
	return 0;
}
