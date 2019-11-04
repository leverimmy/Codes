#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int cnt,tot,n;
char s[100];//用来储存字符串

int main()
{
	scanf("%d",&n);//一共有几轮
	for(int j=1;j<=n;j++)
	{
		scanf("%s",s);//储存
		for(int i=0;i<strlen(s);i++)
		{
			if(s[i]=='O')
			{
				cnt++;
				tot+=cnt;//累加分数
			}
			if(s[i]=='X')
				cnt=0;//一碰到X就清零
		}
		printf("%d\n",tot);//输出总分，换行
		tot=0;
		cnt=0;//每一轮过后都要记得归零【重要！】
	}
	return 0;
}