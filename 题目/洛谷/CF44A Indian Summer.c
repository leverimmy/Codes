#include <stdio.h>
#include <stdlib.h>
struct leaf
{
	char kind[10];
    char color[10];
}a[110];
int main()
{
    int n,i,count=0,j,flag[110];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
		scanf("%s %s",a[i].kind,a[i].color);
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
			if((a[i].color==a[j].color)&&(a[i].kind==a[j].kind)&&((flag[i]!=1)||(flag[j]!=1)))
			{
				count++;
                flag[i]=1;
                flag[j]=1;
            }
    }
    printf("%d",n-count);
	system("pause");
	return 0;
}
