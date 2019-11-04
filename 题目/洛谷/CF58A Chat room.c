#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char hello[]={'h','e','l','l','o'};
    char a[110];
    int i,j=0,len;
    scanf("%s",a);
    len=strlen(a);
    for(i=0;i<len;i++)
    {
		if(a[i]==hello[j])
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
