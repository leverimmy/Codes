#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

char c[50];
int len,flag=-1;

int main()
{
	scanf("%s",c);
	len=strlen(c);
	for(int i=0;i<len;i++)
	{
		//如果是分数，那么这么反转：
		if(c[i]=='/')
		{
			flag=0;//设置一个flag，那么就不会重复输出
			int temp,t,tem;
			t=tem=temp=i;
			char cfront[50],cback[50];
			for(int j=0;j<temp;j++)
				cfront[j]=c[temp-j-1];//反转，这里的temp-j-1要自己在纸上试一下
			while(cfront[0]=='0' && temp>1)//删除前导零，但是要注意，位数不能为零，所以要加上“&& temp>1”
			{
				temp--;
				for(int j=0;j<temp;j++)
					cfront[j]=cfront[j+1];//所有的数都往前移一位
			}
			for(int j=0;j<temp;j++)
				printf("%c",cfront[j]);//输出分数线前面的
			printf("/");//输出分数线
			int lenback=len-t-1;
			for(int j=0;j<lenback;j++)
				cback[j]=c[len-j-1];
			while(cback[0]=='0')//这里分母不会为零，所以就不用加上“&& temp>1”
			{
				lenback--;
				for(int j=0;j<lenback;j++)
					cback[j]=cback[j+1];
			}
			for(int j=0;j<lenback;j++)
				printf("%c",cback[j]);//输出分数线后面的
		}
		//如果是小数，那么这么反转：
		if(c[i]=='.')
		{
			flag=0;
			int temp,t,tem;
			t=tem=temp=i;
			char cfront[50],cback[50];
			for(int j=0;j<temp;j++)
				cfront[j]=c[temp-j-1];//反转，这里其实和分数一样
			while(cfront[0]=='0' && temp>1)
			{
				temp--;
				for(int j=0;j<temp;j++)
					cfront[j]=cfront[j+1];
			}
			for(int j=0;j<temp;j++)
				printf("%c",cfront[j]);
			printf(".");//除了这个地方
			int lenback=len-t-1;
			for(int j=0;j<lenback;j++)
				cback[j]=c[len-j-1];
			while(cback[0]=='0' && lenback>1)
			{
				lenback--;
				for(int j=0;j<lenback;j++)
					cback[j]=cback[j+1];
			}
			while(cback[lenback-1]=='0' && lenback>1)
				lenback--;
			for(int j=0;j<lenback;j++)
				printf("%c",cback[j]);
		}//那我就不多说了，这里的代码和分数几乎是一样的
	}
	//如果是百分数，那么这么反转：
	if(c[len-1]=='%')//如果末位为“%”，那么就为百分数
	{
		flag=0;//避免重复输出
		c[len-1]='0';//把“%”变为0，这样好删除一些
		char c1[50];
		for(int i=0;i<len;i++)
			c1[i]=c[len-i-1];
		while(c1[0]=='0' && len>1)//删除前导零，这里同理，要加上“&& len>1”
		{
			len--;
			for(int i=0;i<len;i++)
				c1[i]=c1[i+1];
		}
		for(int i=0;i<len;i++)
			printf("%c",c1[i]);
		printf("%%");
	}
	//如果是整数，那么这么反转：
	if(flag==-1)//防止重复输出
	{
		char c1[50];
		for(int i=0;i<len;i++)
			c1[i]=c[len-i-1];
		while(c1[0]=='0' && len>1)//删除前导零，这里同理，要加上“&& len>1”
		{
			len--;
			for(int i=0;i<len;i++)
				c1[i]=c1[i+1];
		}
		for(int i=0;i<len;i++)
			printf("%c",c1[i]);
	}
	return 0;
}