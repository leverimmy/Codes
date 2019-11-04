#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;
int a,b,c;
int main()
{
	char script[280];
	int i,len;
	scanf("%s",script);
	len=strlen(script);
	for(i=0;i<len;i++)
	{
		if(script[i]=='a')
		{
			if(script[i+3]=='b')
				a=b;
			else if(script[i+3]=='c')
				a=c;
			else if(script[i+3]>='0' && script[i+4]!=';' && script[i+3]<='9')
				a=10*(script[i+3]-'0')+script[i+4]-'0';
			else if(script[i+3]>='0' && script[i+4]==';' && script[i+3]<='9')	
				a=script[i+3]-'0';
			
		}
		if(script[i]=='b')
		{
			if(script[i+3]=='a')
				b=a;
			else if(script[i+3]=='c')
				b=c;
			else if(script[i+3]>='0' && script[i+4]!=';' && script[i+3]<='9')
				b=10*(script[i+3]-'0')+script[i+4]-'0';
			else if(script[i+3]>='0' && script[i+4]==';' && script[i+3]<='9')	
				b=script[i+3]-'0';
		}
		if(script[i]=='c')
		{
			if(script[i+3]=='b')
				c=b;
			else if(script[i+3]=='a')
				c=a;
			else if(script[i+3]>='0' && script[i+4]!=';' && script[i+3]<='9')
				c=10*(script[i+3]-'0')+script[i+4]-'0';
			else if(script[i+3]>='0' && script[i+4]==';' && script[i+3]<='9')	
				c=script[i+3]-'0';
		}
	}
	printf("%d %d %d",a,b,c);
	return 0;
}