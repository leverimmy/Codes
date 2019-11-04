#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int i,j,k,len,count=0;
    char a[1000];
    gets(a);
    len=strlen(a);
    for(i=0;i<len;i++)
		for(j=i+1;j<len;j++)
			for(k=j+1;k<len;k++)
				{
					if((a[i]=='Q')&&(a[j]=='A')&&(a[k]=='Q'))
						count++;
                }
    printf("%d",count);
	system("pause");
	return 0;
}
