#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char h[]={'h','e','i','d','i'};
    char a[1000];
    int i,j=0,len;
    scanf("%s",a);
    len=strlen(a);
    for(i=0;i<len;i++)
    {
		if(a[i]==h[j])
			j++;
        if(j==5)
			break;
    }
    if(j==5)
		printf("YES");
    else
		printf("NO");
	system("pause");
	return 0;
}
