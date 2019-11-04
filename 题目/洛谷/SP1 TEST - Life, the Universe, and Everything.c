#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a;
    while(1)//暴力循环
    {
		scanf("%d",&a);
        if(a==42)//一旦读入为42
			break;//暂停
		printf("%d\n",a);//读入什么输出什么
    }
	system("pause");
	return 0;
}
