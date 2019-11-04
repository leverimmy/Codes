#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char a[1200];
    int b,c=0,i;
    scanf("%s",a);
    b=strlen(a);
    if(a[0]=='-')
		{
            printf("-");
            c++;
        }
	while(a[b-1]=='0')
		b--;
    for(i=b-1;i>=c;i--)
		printf("%c",a[i]);
	system("pause");
	return 0;
}
