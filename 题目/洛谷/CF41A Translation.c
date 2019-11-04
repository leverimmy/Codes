#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[10000];
    char b[10000];
    char c[10000];
    int flag=1,lena,lenb,i;
    gets(a);
    gets(b);
    lena=strlen(a);
    lenb=strlen(b);
    for(i=0;i<lenb;i++)
		c[i]=b[lenb-i-1];
    if(lena!=lenb)
		flag=0;
    else
		{
			for(i=0;i<lena;i++)
				if(a[i]!=c[i])
					flag=0;
        }
    if(flag==0)
		printf("NO");
    else
		printf("YES");
	system("pause");
	return 0;
}
