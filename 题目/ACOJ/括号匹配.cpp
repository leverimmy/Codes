#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	char s[110],stack[110];
	int top=0,i,flag=1;
	scanf("%s",s);
	int len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]=='{'||s[i]=='['||s[i]=='(')
			stack[++top]=s[i];
		if(s[i]=='}')
			if(stack[top]=='{')
				top--;
			else
			{
				flag=0;
				break;
			}
		if(s[i]==']')
			if(stack[top]=='[')
				top--;
			else
			{
				flag=0;
				break;
			}
		if(s[i]==')')
			if(stack[top]=='(')
				top--;
			else
			{
				flag=0;
				break;
			}
	}
	if(len%2==1)
		flag=0;
	if(flag)
		printf("YES");
	else
		printf("NO");
	return 0;
}