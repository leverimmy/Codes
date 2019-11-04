#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char a[100];
    int len,i;
    scanf("%d",&len);
    scanf("%s",a);
    len=strlen(a);
    
    if(len%2==0)
	{
		for(i=0;i<len;i++)
        {
			if(i%2==0 && i!=0)
				printf("-");
			printf("%c",a[i]);
			
        }
    }
    if(len%2!=0)
    {
		for(i=0;i<len;i++)
        {
			if(i%2==0 && i!=0 && i!=len-1)
				printf("-");
			printf("%c",a[i]);
            
        }
    }
	system("pause");
	return 0;
}
