#include <stdio.h>
#include <stdlib.h>
int main()
{
	int k,i=1;
    double s=0;
    scanf("%d",&k);
    while(s<=k)
		{
			s=s+1.0/i;
            if(s>k) break;
            i++;
        }
    printf("%d ",i);
	system("pause");
	return 0;
}
