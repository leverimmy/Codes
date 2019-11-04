#include <stdio.h>
#include <stdlib.h>
int zuigao(int x)
{
	int t=0;
	while(x)
    {
		t=10*t+x%10;
		x=x/10;
    }
    t=t%10;
    return t;
}
int main()
{
	int l,r,i;
    int count=0;
    int gao,di;
    scanf("%d %d",&l,&r);
    for(i=l;i<=r;i++)
		{
			di=i%10;
            gao=zuigao(i);
            if(gao==di)
				count++;
        }
    printf("%d",count);
	system("pause");
	return 0;
}
