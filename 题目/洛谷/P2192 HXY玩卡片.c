#include <stdio.h>
#include <stdlib.h>
int five,zero,n,m,t;
int main()
{
	int i;
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
		scanf("%d",&t);
        if(t==0)
			zero++;
        else
			five++;
    }
    if(zero==0)
		printf("-1");
    else if(zero!=0 && five<9)
		printf("0");
    else if(zero!=0 && five>=9)
    {
		while(five>=9)
        {
			five=five-9;
            n++;
        }
        for(i=0;i<n*9;i++)
			printf("5");
        for(i=0;i<zero;i++)
			printf("0");
    }
	system("pause");
	return 0;
}
