#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

char key[20];//这是要找的单词
char words[1000010];//这是原文
char t;
int cnt,first=-1,lenkey,lenwords,k;

int main()
{
	gets(key);
	gets(words);//两个读入
	lenkey=strlen(key);
	lenwords=strlen(words);//这两个是字符串长度
	for(int i=0;i<lenkey;i++)
		key[i]=tolower(key[i]);
	for(int i=0;i<lenwords;i++)
		words[i]=tolower(words[i]);//全部转换为小写字母
	t=key[0];//设置一个变量，为单词的第一个字母
	for(int i=0;i<=lenwords-lenkey;i++)
	{
		if(words[i]==t)//如果找到了可以匹配单词第一个字母的字母
			if(i==0 || words[i-1]==' ')//除开头外，前面要为空格
			{
				for(int j=1;j<lenkey;j++)
					if(words[i+j]!=key[j])//如果中间匹配失败
					{
						k=1;//把k置为1
						break;//提前结束循环
					}
				if(k==0)//如果都匹配完毕
					if(i+lenkey==lenwords || words[i+lenkey]==' ')//除结尾外，后面要为空格
					{
						cnt++;
						if(first==-1)//这里如果first变量没有改变，就置为第一次出现的位置
							first=i;
					}
				k=0;//记得每轮之后要归零
				}
	}
	if(first==-1)
		printf("-1");//如果没有找到，就输出
	else
		printf("%d %d",cnt,first);
	return 0;
}