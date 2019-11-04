#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char a[200][200];
    int N,i,j,spot;
    int sum=0;
    scanf("%s",a[1]);
    N=strlen(a[1]);
    printf("%d ",N);
    for(i=2;i<=N;i++)
		scanf("%s",a[i]);
    spot=0;
    for(i=1;i<=N;i++)
        for(j=0;j<N;j++)
        {
			if(a[i][j]-'0'==spot)
				sum++;
            else
			{
				printf("%d ",sum);
                sum=1;
                spot=!spot;
            }
        }
    printf("%d",sum);
	system("pause");
	return 0;
}
