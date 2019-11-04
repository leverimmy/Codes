#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>

using namespace std;

int len,cnt,flag=1;
char s[110];

int main()
{
	gets(s);
	len=strlen(s);
	for(int i=len-1;i>=0;i--)
		if(isalpha(s[i])!=0)
			if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' && s[i]!='A' && s[i]!='E' && s[i]!='I' && s[i]!='O' && s[i]!='U' && s[i]!='Y')
			{
				flag=0;
				break;
			}
			else
			{
				flag=1;
				break;
			}
	if(flag)
		printf("YES");
	else
		printf("NO");
	return 0;
}