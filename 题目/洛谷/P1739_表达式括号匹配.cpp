#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int flag=1;
int len,p;
char s[1111];
int main()
{
	scanf("%s",s);
	len=strlen(s);
	for(int i=0;i<=len;i++)
	{
		if(s[i]=='@')
			break;
		if(s[i]=='(')
			p++;
		if(s[i]==')')
			p--;
		if(p<0)
		{
			flag=0;
			break;
		}
	}
	if(flag==0)
		printf("NO");
	else
	{
		if(p>0)
			printf("NO");
		else
			printf("YES");
	}
}	