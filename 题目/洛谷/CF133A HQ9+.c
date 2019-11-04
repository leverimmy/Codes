#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char a[10000];//存储字符串
    int len,i,flag=0;
    /*
		len是字符串的长度；
        i是循环用的；
        flag是看它有没有要求的字母
    */
    scanf("%s",a);//输入字符串
    len=strlen(a);//求长度
    for(i=0;i<len;i++)//遍历
		if(a[i]=='H' || a[i]=='Q' || a[i]=='9')//如果有
			flag=1;
    if(flag==1)
		printf("YES");
    else
		printf("NO");
	system("pause");
	return 0;//完美结束
}
