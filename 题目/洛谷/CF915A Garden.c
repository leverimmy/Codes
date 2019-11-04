#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,k,i,min=10000,ans=0,t;
/*
	n,k是题目里面的量；
    i是用来循环的量；
    min来存储最小值（所以预设值要尽量的大）；
    ans来储存比值；
    t是用来储存数据的临时变量。
*/
    scanf("%d %d",&n,&k);//先输入n与k
    for(i=0;i<n;i++)
    {
		scanf("%d",&t);//输入到一个变量t里面
        if(k%t==0)//先看能不能整除
		{
			ans=k/t;
			if(ans<min)//如果还有更小的
				min=ans;//更新答案
        }
    }
    printf("%d",min);//把最小的输出
	system("pause");
	return 0;
}
