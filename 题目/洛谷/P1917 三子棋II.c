#include <stdio.h>
#include <stdlib.h>
int flag;
/*
	如果flag=0；则平局；
    如果flag=1；小a赢；
*/
int main()
{
	char a[3][3];
    int i,j,count=0;
    for(i=0;i<3;i++)
		scanf("%s",a[i]);
    for(i=0;i<3;i++)
		for(j=0;j<3;j++)
        {
			if(a[i][j]!='-')
				count++;
        }
    if(a[0][1]=='X' || a[1][0]=='X' || a[1][2]=='X' || a[2][1]=='X')
		flag=1;
    else 
		flag=0;
    if(flag==1)
		printf("xiaoa will win.\n");
    if(flag==0)
		printf("Dont know.\n");
    printf("%d",count);
	system("pause");
	return 0;
}
