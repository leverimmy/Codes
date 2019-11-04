#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char a[10000];
    int i,len;
    scanf("%s",a);
    len=strlen(a);
    for(i=0;i<len;i++)
	{
		if(a[i]=='.')
			printf("0");
        else 
			if(a[i]=='-')
				if(a[i+1]=='.')
				{
					printf("1");
                    i++;
                }
				else 
					if(a[i+1]=='-')
					{	
                        printf("2");
                        i++;
                    }
    }
	system("pause");
	return 0;
}
