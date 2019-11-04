#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int wei(int n)
{
	int count=0;
	while(n)
    {
		n=n/10;
        count++;
    }
    return count;
}
int main()
{
	int flag=0;
	int m,n,i,ge,shi,bai,qian,wan,j;
    scanf("%d %d",&m,&n);
    for(i=m;i<=n;i++)
    {
		if(wei(i)==2)
        {
			shi=i/10;
            ge=i%10;
            j=pow(shi,2)+pow(ge,2);
            if(i==j)
			{	
                printf("%d\n",i);
                flag=1;
            }
        }
        else if(wei(i)==3)
        {
			bai=i/100;
            shi=i/10%10;
            ge=i%10;
            j=pow(bai,3)+pow(shi,3)+pow(ge,3);
            if(i==j)
			{	
                printf("%d\n",i);
                flag=1;
            }
        }
        else if(wei(i)==4)
        {
			qian=i/1000;
            bai=i/100%10;
            shi=i/10%10;
            ge=i%10;
            j=pow(qian,4)+pow(bai,4)+pow(shi,4)+pow(ge,4);
            if(i==j)
			{	
                printf("%d\n",i);
                flag=1;
            }
        }
        else if(wei(i)==5)
        {
			wan=i/10000;
            qian=i/1000%10;
            bai=i/100%10;
            shi=i/10%10;
            ge=i%10;
            j=pow(wan,5)+pow(qian,5)+pow(bai,5)+pow(shi,5)+pow(ge,5);
            if(i==j)
			{	
                printf("%d\n",i);
                flag=1;
            }
        }
    }
    if(flag==0)
		printf("No solution!");
	system("pause");
	return 0;
}
