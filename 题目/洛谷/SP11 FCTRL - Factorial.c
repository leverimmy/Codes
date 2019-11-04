#include <stdio.h>
#include <stdlib.h>
int z(int n)//我们设置一个统计有多少个质因数5的函数
{
	int i,j,count=0;
	while(n)
    {
		while(n)
        {
			count=count+n/5;
            n=n/5;
        }//不断循环累加
    }
    return count;

}
int main()
{
	int n,i;
    int t;
    scanf("%d",&n);
    for(i=0;i<n;i++)//一共n组数据
	{
		scanf("%d",&t);
		printf("%d\n",z(t));//用z()函数
    }
	system("pause");
	return 0;
}
