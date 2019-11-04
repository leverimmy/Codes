#include <stdio.h>
#include <stdlib.h>
int count1(int x)
{
	int count=0,t;
    while(x)
    {
		t=x%10;
        x=x/10;
        if(t==1)	count++;
    }
    return count;
}
int main()
{
	int i,n,count=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
		count=count+count1(i);
    printf("%d",count);
	system("pause");
	return 0;
}
