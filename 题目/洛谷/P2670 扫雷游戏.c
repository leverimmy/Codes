#include <stdio.h>
#include <stdlib.h>
int main()
{
	int  a[110][110]={0};
    int b[110][110]={0};
    int m,n,i,j,sum;
    char t[110];
    scanf("%d %d\n",&n,&m);
    for(i=1;i<=n;i++)
	{	
        scanf("%s",t);
        for(j=0;j<m;j++)
		{
            if(t[j]=='*')
				a[i][j+1]=1;
        }
    }
/*    for(i=1;i<=n;i++)
	{	
        for(j=1;j<=m;j++)
			printf("%d",a[i][j]);
        printf("\n");
    }
*/    
    for(i=1;i<=n;i++)
	{
    	for(j=1;j<=m;j++)
		{
				if(a[i][j]==1)
					printf("*");
                else
				{
					printf("%d",a[i+1][j+1]+a[i+1][j-1]+a[i+1][j]+a[i][j+1]+a[i][j-1]+a[i-1][j+1]+a[i-1][j]+a[i-1][j-1]);
                }
        }
        printf("\n");
    }
	system("pause");
	return 0;
}
