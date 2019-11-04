#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{    
    char a[1000000];
    char b[1000000];
    int flag=1,i,n;
    gets(a);
    n=strlen(a);	
    for(i=0;i<n;i++)
		b[i]=a[n-i-1];
    for(i=0;i<n;i++)
		if(a[i]!=b[i])
			flag=0;
    if(flag==1)	printf("Yes");
    else	printf("No");
	system("pause");
	return 0;
}
