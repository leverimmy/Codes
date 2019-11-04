#include <stdio.h>
#include <stdlib.h>
int main()
{
	int l,r,i,n,count=0;
    scanf("%d %d",&l,&r);
    for(i=l;i<=r;i++)
		{
			n=i;
            while(n)
			{
				if(n%10==2)
					count++;
                n=n/10;
            }
        }
    printf("%d",count);        
	system("pause");
	return 0;
}
