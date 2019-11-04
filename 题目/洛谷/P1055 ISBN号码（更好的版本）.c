#include <stdio.h>
#include <stdlib.h>
int main()
{
	char a[100];
    int i,j=1,s,sum=0;
    gets(a);
    for(i=0;i<=11;i++)
    {
		if(a[i]!='-')
			{	
                sum=sum+((int)a[i]-'48')*j;
				j++;
            }
    }
    s=(char)(sum%11+48);
    if(sum%11==10)
		s='X';
	if(a[12]==s)
		printf("Right");
    else
		{
			for(i=0;i<=11;i++)
				printf("%d",a[i]);
            printf("%d",a[12]);
        }
	system("pause");
	return 0;
}
