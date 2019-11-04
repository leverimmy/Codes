#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,j,t,count=0,max=100;
    int a[1010][1010];
    scanf("%d",&n);
    for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
		for(j=0;j<n;j++)
        {
			if(a[i][j]==0)
            {
				for(t=0;t<n;t++)
				{
					if(a[t][j]==1)
						count++;
                    if(a[i][t]==1)
						count++;
                }
            }
            if(count>max)
				max=count;
        }
    printf("%d",count);
	system("pause");
	return 0;
}
