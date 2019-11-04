#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i;
	int t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
		scanf("%d",&t);//输入要判断的数
        if(t%2==0)
			printf("pb wins\n");//如果是偶数，就是pb赢
        if(t%2==1)
			printf("zs wins\n");//如果是奇数，就是zs赢
    }
	system("pause");
	return 0;
}
