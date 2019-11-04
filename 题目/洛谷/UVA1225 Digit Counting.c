#include <stdio.h>
#include <stdlib.h>
int digit[10];/*在外面定义，免得初始化*/
int main()
{
	int i,n,x,m,j,k,l;
    scanf("%d",&n);/*先看有几组数据*/
    for(i=0;i<n;i++)/*读入n组数据：*/
    {
		scanf("%d",&m);/*看要循环到哪一个数*/
        for(j=1;j<=m;j++)/*枚举1~m所有数*/
        {
			x=j;/*找个替身，避免重复使用同一个变量*/
            while(x)/*最关键的一步：当x不为0的时候执行循环（也就是当这个数所有的数位都被去掉的时候）*/
            {
				digit[x%10]++;/*也就是从末位开始判断：x%10为这个数的末位，相应的digit[]++；*/
                x=x/10;/*把末位去掉
            }
        }
        for(k=0;k<9;k++)
			printf("%d ",digit[k]);/*世纪大坑：前9个数码后面有空格*/
        printf("%d\n",digit[9]);/*最后一个没有，并且还要换行……*/
        for(l=0;l<10;l++)
			digit[l]=0;
    }
	/*system("pause");*/
	return 0;
}
