#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
	char a[1000];
    int len,flag=1,i;
    gets(a);
    len=strlen(a);
    while(isalpha(a[len-1])==0)
		len--;
    //printf("%d",len);
    len++;
    if((a[len]=='a')||(a[len]=='e')||(a[len]=='i')||(a[len]=='o')||(a[len]=='u')||(a[len]=='y')||(a[len]=='A')||(a[len]=='E')||(a[len]=='I')||(a[len]=='O')||(a[len]=='U')||(a[len]=='Y'))
		flag=1;
    else
		flag=0;
    if(flag==1)
		printf("YES");
    else
		printf("NO");
    system("pause");
	return 0;
}
