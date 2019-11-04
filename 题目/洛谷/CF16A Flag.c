#include <stdio.h>
#include <stdlib.h>

int n,m,flag=1;
int s[105][105];
int i,j;

int main()
{
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			char t;
			scanf("%c",&t);
			s[i][j]=t-'0';
		}
	for(i=1;i<=n;i++)
		for(j=2;j<=m;j++)
		{
			if(s[i][j]==s[i+1][j])
			{
				flag=0;
				break;
			}
	for(i=2;i<=n;i++)		
			if(s[i][1]==s[i-1][1])
			{
				flag=0;
				break;
			}
		}
    if(flag)
		printf("YES");
    else
		printf("NO");
    system("pause");
	return 0;
}
