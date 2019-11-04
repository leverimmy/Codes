#include <stdio.h>
#include <stdlib.h>
int main()
{
	char a[7];
    int i,sum=0;
    scanf("%s",a);
    for(i=0;i<7;i++)
    {
		if(a[i]=='A')
			sum=sum+1;
        else if(a[i]=='1')
			sum=sum+10;
        else
			sum=sum+a[i]-'0';
    }
    printf("%d",sum);
	system("pause");
	return 0;
}
