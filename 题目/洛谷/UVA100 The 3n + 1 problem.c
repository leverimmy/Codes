#include <stdio.h>
#include <stdlib.h>
int threen(int n)
{
	int count=1;
	while(n!=1)
    {
		if(n%2!=0)
		{
			n=3*n+1;
            count++;
        }
        else
		{
			n=n/2;
            count++;
        }
    }
    return count;
}
int main()
{
	int a,b,i,count,max=-100;
	while(scanf("%d %d",&a,&b))
    {
		for(i=a;i<=b;i++)
        {
			count=threen(i);
            if(count>max)
				max=count;
        }
        printf("%d %d %d\n",a,b,max);
        max=-100;
    }
	system("pause");
	return 0;
}
