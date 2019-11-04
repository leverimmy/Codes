#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	char s[110];
	char t[110];
	int flag=1;
	int i,len;
	scanf("%s",s);
	len=strlen(s);
	for(i=0;i<len;i++)
		t[i]=s[len-i-1];
	for(i=0;i<len;i++)
		if(s[i]!=t[i])
		{
			flag=0;
			break;
		}
	if(len==1)
		flag=1;
	if(flag)
		printf("YES");
	else
		printf("NO");
	return 0;
}