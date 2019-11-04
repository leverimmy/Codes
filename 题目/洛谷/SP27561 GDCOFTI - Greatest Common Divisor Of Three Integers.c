#include <stdio.h>
#include <stdlib.h>
int min(int m,int n)
{
	if(m<=n)
		return m;
    else
		return n;
}//我们自定义一个min()函数
int main()
{
	int a,b,c,maxn=-100,i,minn;//maxn初值要设的小一点
    scanf("%d\n%d\n%d",&a,&b,&c);
    minn=min(min(a,b),c);//把三个数中最小的先找出来，减少循环的次数
    for(i=1;i<=minn;i++)
		if((a%i==0)&&(b%i==0)&&(c%i==0))//如果它是三个数的公约数
			if(i>maxn)//更新最大值
				maxn=i;
    printf("%d",maxn);//输出
	system("pause");
	return 0;
}
