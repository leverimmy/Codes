#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[110][110]={0};
    int n,m,r,i,j,k,t1,t2,count=0;
    scanf("%d %d %d",&n,&m,&r);//输入n，m，r
    for(k=0;k<m;k++)
		{
			scanf("%d %d",&t1,&t2);
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
				{
                    if((i-t1)*(i-t1)+(j-t2)*(j-t2)<=r*r)//两点之间距离公式
														//如果在范围内
						a[i][j]=1;//标记一下
				}
        }
    for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j]==1)//如果是在范围内的
				count++;//计数
    printf("%d",count);
	system("pause");
	return 0;
}
