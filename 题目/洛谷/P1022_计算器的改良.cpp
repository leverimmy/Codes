#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int power(int a,int b)
{
	int sum=1;
	for(int i=1;i<=b;i++)
		sum=sum*a;
	return sum;
}

int number(char num[])
{
	if(num[0]!='-')
	{
		int len=strlen(num);
		int sum=0;
		for(int i=0;i<len;i++)
			sum+=power(10,len-i-1)*(num[i]-'0');
		return sum;
	}
	else 	if(num[0]=='-')
	{
		int sum=0;
		int len=strlen(num);
		for(int i=1;i<len;i++)
			sum-=power(10,len-i-1)*(num[i]-'0');
		return sum;
	}
}

char eq[100];
char fq[100];
int len;
int a;
int b;
int c;
int d;
char weizhishu;
char nu[1111];

int main()
{
	scanf("%s",eq);
	len=strlen(eq);
	for(int i=0;i<len;i++)
	{
		if(eq[i]=='+' || eq[i]=='-' || i==0)
		{
			int t=i;
			for(int j=i+1;j<len;j++)
			{
				if(eq[j]=='+' || eq[j]=='-' || i==len-1)
				{
					int s=j;
					if(isalpha(eq[s-1])!=0)
					{
						weizhishu=eq[s-1];
						if(eq[t]=='+')
						{
							for(int p=t+1;p<=s-2;p++)
								nu[p]=eq[p];
							a+=number(nu);
							memset(nu,0,sizeof(nu));
						}
						else if(t==0)
						{
							for(int p=t;p<=s-2;p++)
								nu[p]=eq[p];
							a+=number(nu);
							memset(nu,0,sizeof(nu));
						}
						else if(eq[t]=='-')
						{
							for(int p=t+1;p<=s-2;p++)
								nu[p]=eq[p];
							a-=number(nu);
							memset(nu,0,sizeof(nu));
						}
					}
					else
					{
						if(eq[t]=='+')
						{
							for(int p=t+1;p<=s-2;p++)
								nu[p]=eq[p];
							b+=number(nu);
							memset(nu,0,sizeof(nu));
						}
						else if(t==0)
						{
							for(int p=t;p<=s-2;p++)
								nu[p]=eq[p];
							b+=number(nu);
							memset(nu,0,sizeof(nu));
						}
						else if(eq[t]=='-')
						{
							for(int p=t+1;p<=s-2;p++)
								nu[p]=eq[p];
							b-=number(nu);
							memset(nu,0,sizeof(nu));
						}
					}
					break;
				}
			}
		}
	}
	printf("%d%c+%d",a,weizhishu,b);
	return 0;
}