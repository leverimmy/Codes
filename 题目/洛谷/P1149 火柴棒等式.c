#include <stdio.h>
#include <stdlib.h>
int huo(int x)
{
	int match[10]={6,2,5,5,4,5,6,3,7,6};
    int num=0;
    int k=x;
    while(k>=10)
    {
		num=num+match[k%10];
        k=k/10;
    }
	num=num+match[k];
    return num;
}
int main()
{
	int a,b,c;
    int n,count=0;
    scanf("%d",&n);
    for(a=0;a<=1111;a++)
		for(b=0;b<=1111;b++)
			{
				c=a+b;
                if(huo(a)+huo(b)+huo(c)==n-4)
					count++;
            }
    printf("%d",count);
	system("pause");
	return 0;
}
