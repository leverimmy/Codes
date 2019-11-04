#include <stdio.h>
#include <stdlib.h>
int main()
{
	/*int n,i,j,x,k=1,count1=0,count2=0;
    scanf("%d,%d",&n,&x);
    while(n)
    {
		n=n/10;
        count1++;
    }
    for(i=1;i<count1;i=i+1)
		{
			if(((n/k)%10)==x)
				count2++;
            k=k*10;
        }
    printf("%d",count2);
    */
    int n,x,count=0;
    scanf("%d,%d",&n,&x);
    while(n)
    {
		if((n%10)==x) count++;
        n=n/10;
    }
	printf("%d",count);
	system("pause");
	return 0;
}
