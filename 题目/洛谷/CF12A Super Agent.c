#include <stdio.h>
#include <stdlib.h>
char a[4][4];
int main()
{

    int i,j;
    for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			a[i][j]=getchar();
    if(a[1][1]==a[3][3]&&a[1][2]==a[3][2]&&a[1][3]==a[3][1]&&a[2][1]==a[2][3])
		printf("YES\n");
    else
		printf("NO\n");
    system("pause");
	return 0;
}
