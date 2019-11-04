#include <stdio.h>
#include <stdlib.h>
int main()
{
	int m,n;
    int k,count=0,i,a[1000]={0};
    scanf("%d %d",&m,&n);
    k=n;
    while(k)
    {
		count++;
        k=k/10;
    }
    k=n;
    for(i=0;i<count;i++)
		{
			a[i]=k%10;
            k=k/10;
        }
	printf("%d*%d^%d",a[count-1],m,count-1);
    for(i=count-2;i>=0;i--)
		{
			if(a[i]!=0)
				printf("+%d*%d^%d",a[i],m,i);
        }
	system("pause");
	return 0;
}
