#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,x,y,a,b,count=0,i;
    scanf("%d %d %d",&n,&x,&y);
    for(i=0;i<n;i++)
    {
		scanf("%d %d",&a,&b);
        if(a<=x && b<=y)
			count++;
    }
    printf("%d",count);
	system("pause");
	return 0;
}
