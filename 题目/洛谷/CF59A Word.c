#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
	char a[1000];
    int len;
    int i,daxie=0,xiaoxie=0;
    gets(a);
    len=strlen(a);
    for(i=0;i<len;i++)
		{
			if(isalpha(a[i])==2)
				xiaoxie++;
			if(isalpha(a[i])==1)
				daxie++;
		}
    if(daxie>xiaoxie)
		{
			for(i=0;i<len;i++)
				if(isalpha(a[i])==2)
					a[i]=a[i]-32;
        }
    else
		{
			for(i=0;i<len;i++)
				if(isalpha(a[i])==1)
					a[i]=a[i]+32;
        }
    puts(a);
	system("pause");
	return 0;
}
