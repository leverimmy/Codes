/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int n;
    int len,i;
    char a[1000];//a数组用来存字符串
    int t;//t用来存最后一位
    scanf("%d",&n);
    for(i=0;i<n;i++)//一共有n组数据
		{
			scanf("%s",a);//先读入
            len=strlen(a);
            t=a[len-1]-'0';//t存的是最后一位
            if(t%2==0)
				printf("even\n");
            else
				printf("odd\n");
        }
	system("pause");
	return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int n;
    int len,i;
    char a;
    int t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
		{
			while(scanf("%c",&a)!="\n")
				t=a-'0';
            if(t%2==0)
				printf("even\n");
            else
				printf("odd\n");
        }
	system("pause");
	return 0;
}
