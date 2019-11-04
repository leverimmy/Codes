#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,j,n,x,count,boo;
    count=0;
    boo=0;
    scanf("%d %d",&n,&x);
    for(i=1;i<=n;i++)
		{
			j=i;
			boo=0;
			if(j%10==x)
				count=count+1;
			if(j<10)
				boo=1;
			while(!boo)
				{
					j=j/10;
					if(j%10==x)
						count=count+1;
					if(j<10)
						boo=1;
				}
        }
    printf("%d",count);
	system("pause");
	return 0;
}
