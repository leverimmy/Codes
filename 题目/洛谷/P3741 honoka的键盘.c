#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,count=0,flag=0;
    char a[100];
    scanf("%d",&n);
    scanf("%s",a);
    for(i=0;i<n-1;i++)//从0循环到n-2，要不然会越界
    {
		if(a[i]=='V' && a[i+1]=='K')
        {
			count++;
            a[i]='XZE';
            a[i+1]='PZY';//随便再把这两个位置换个东西，避免后面重复计算
        }
    }
    for(i=0;i<n-1;i++)
		if(a[i]==a[i+1])
			flag=1;//如果还有相邻的是同一个字母，将flag置为1
    if(flag==0)
		printf("%d",count);
    else
		printf("%d",++count);//如果还可以再做一次改变，那就加1
	system("pause");
	return 0;
}
