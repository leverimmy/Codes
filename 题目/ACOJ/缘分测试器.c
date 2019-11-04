#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int san(int x,int y)
{
	int san;
    san=3*x*y+1;
    return san;
}
int main()
{
    int a=0,b=0,yuan,m,n,i;
    char c1[10]={0},c2[10]={0};
    printf("Made by Clever_Jimmy\n");
    printf("请分别输入您和TA的名字的简写（用小写）\n用回车隔开，系统将自动输出缘分值：\n");
    printf("您的姓名：");
    gets(c1);
    printf("TA的姓名：");
    gets(c2);
    m=strlen(c1);
    n=strlen(c2);
    for(i=0;i<m;i++)
		a=a+c1[i]-'0';
    for(i=0;i<n;i++)
		b=b+c2[i]-'0';
    if(abs(a-b)<=5)
		{
			printf("终生不合，换个人吧!\n");
            system("pause");
            return 0;
        }
    else
		{
			if(abs(a-b)==6)
				{
					printf("缘分值为：100\n");
					system("pause");
					return 0;
				}
			else 
				{
					yuan=a*b+a+b;
					while(yuan>100)
						{
							a--;
							b--;
							yuan=san(a,b);
						}
					printf("缘分值为：");
					printf("%d\n",yuan);
					system("pause");
					return 0;
				}
        }
}
