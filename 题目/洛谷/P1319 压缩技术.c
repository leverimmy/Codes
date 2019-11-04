#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,n,line=0,spot=0,i,r;
    scanf("%d",&n);
    r=n*n;
    while(r)
	{
		scanf("%d",&a);
        r=r-a;
		for(i=0;i<a;i++)
		{
			printf("%d",spot);
            line++;
            if(line==n)
            {
				line=0;
                printf("\n");
            }
        }
		spot=!spot;
    }
	system("pause");
	return 0;
}
