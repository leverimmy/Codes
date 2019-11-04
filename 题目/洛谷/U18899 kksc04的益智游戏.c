#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b,c,d,e,f,i,count=0,t;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    for(i=0;i<a*b+c*d+e*f;i++)
	{
		scanf("%d",&t);
        if(t!=0)
			count++;
    }
    printf("%d",count*2);
	system("pause");
	return 0;
}
