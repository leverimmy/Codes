#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int alp[26];
char a[100],b[100],x[100];
char ans[26];
int main()
{
	int i,j,len,len2,flag=1;
	scanf("%s %s %s",a,b,x);
    len=strlen(a);
    len2=strlen(x);
    if(len<26)
		flag=0;
    for(i=0;i<len;i++)
	{
    	for(j=0;j<len;j++)
		{
			if(b[i]==b[j] && a[i]!=a[j])
				flag=0;
        }
        ans[a[i]-'A']=b[i];
    }
    if(flag==0)
		printf("Failed");
    else
    {
		for(i=0;i<len2;i++)
			printf("%c",ans[x[i]-'A']);
    }
	system("pause");
	return 0;
}
