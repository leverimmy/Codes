#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct pre//一个结构体
{
	int num;//序号
    char vote[110];//因为题目中明确表示了，可能票数有100位之多（宇宙里应该确实有这么多“人”），所以我们用字符串来存储
}a[30],t;
int main()
{
	int n,i,j,len1,len2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
		a[i].num=i+1;//每个人的序号是i+1，因为i是从0开始算的
        scanf("%s",a[i].vote);//存储票数
    }
    for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{
			len1=strlen(a[j].vote);
            len2=strlen(a[j+1].vote);
        	if(len1<len2)
            {
				t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
			else if((len1==len2)&&(strcmp(a[j].vote,a[j+1].vote)<0))
			{
				t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }//冒泡排序
    printf("%d\n%s",a[0].num,a[0].vote);
	system("pause");
	return 0;
}
