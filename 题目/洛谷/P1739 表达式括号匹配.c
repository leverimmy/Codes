#include <stdio.h>
#include <stdlib.h>
int main()
{
	char a[300];
    int i=0,len,left=0,right=0;
    scanf("%s",a);
    len=strlen(a);
    for(i=0;i<len-1;i++)//len-1是因为要减去'@'
		{
			if(a[i]=='(')
				left++;
            if(a[i]==')')
				right++;//计算左右括号的数量
        }
    if(left!=right)//如果左右括号的数量都不等，肯定不行
		{
			printf("NO");
            system("pause");
			return 0;
        }
	else
    {
		left=0;
        right=0;
        for(i=0;i<len-1;i++)
		{
			if(a[i]=='(')
				left++;
            if(a[i]==')')
				left--;//抵消一组括号
            if(left<0)//每次都要判断一次，看左括号的数量是否＜0
				{
					printf("NO");
                    system("pause");
					return 0;
                }
        }
    
		printf("YES");
		system("pause");
		return 0;
    }
		
}

