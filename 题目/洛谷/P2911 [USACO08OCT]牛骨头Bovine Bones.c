#include <stdio.h>
#include <stdlib.h>
int dice[100];
int max=-100,ans;
int main()
{
	int s1,s2,s3,i,j,k;
    scanf("%d %d %d",&s1,&s2,&s3);
    for(i=1;i<=s1;i++)
		for(j=1;j<=s2;j++)
			for(k=1;k<=s3;k++)
				dice[i+j+k]++;
    for(i=1;i<=s1+s2+s3;i++)
    {
		if(dice[i]>max)
        {
			max=dice[i];
            ans=i;
        }
    }
    printf("%d",ans);
	system("pause");
	return 0;
}
