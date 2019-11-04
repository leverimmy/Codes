#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char s[300];
    int len,i,a=0,b=0,c=0;
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
		if(s[i]=='a')
        {
			if(s[i+3]!='b' && s[i+3]!='c' && s[i+3]!='a')
				a=s[i+3]-'0';
            else if(s[i+3]=='b')
				a=b;
            else if(s[i+3]=='c')
				a=c;
            else if(s[i+3]=='a')
				a=a;
        }
        if(s[i]=='b')
		{
			if(s[i+3]!='a' && s[i+3]!='c' && s[i+3]!='b')
				b=s[i+3]-'0';
            else if(s[i+3]=='a')
				b=a;
            else if(s[i+3]=='c')
				b=c;
        }
        if(s[i]=='c')
        {
			if(s[i+3]!='a' && s[i+3]!='b' && s[i]!='c')
				c=s[i+3]-'0';
            else if(s[i+3]=='a')
				c=a;
            else if(s[i+3]=='b')
				c=b;
        }
    }
    printf("%d %d %d",a,b,c);
	system("pause");
	return 0;
}
