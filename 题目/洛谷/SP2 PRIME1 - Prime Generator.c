#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int prime(int n)//判断质数的函数
{
	int i;
    if(n<2)//小于2的数绝对不是质数
		return 0;
    else
    {
		for(i=2;i<=sqrt(n);i++)//从2循环到$\sqrt{n}$
			if(n%i==0)//如果能够整除
				return 0;//那就不是质数
        return 1;
    }
}
int main()
{
	int n;
    int i,j,t1,t2;
    scanf("%d",&n);//一共n组数据
    for(i=1;i<=n;i++)
		{
			scanf("%d %d",&t1,&t2);//t1为左界限，t2为右界限
			for(j=t1;j<=t2;j++)//从左界限循环到右界限
				{
					if(prime(j)==1)//如果是质数
						printf("%d\n",j);//输出，换行
                }
            printf("\n");//每组都换行
        }
	system("pause");
	return 0;
}
