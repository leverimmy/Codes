#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,m,t,i;
    int sum1=0,sum2=0,sum=0;
    scanf("%d %d",&n,&m);
    if(n>m)
		{
			t=n;
            n=m;
            m=t;
        }
	for(i=1;i<=n;i++)
		sum1=sum1+(m-i+1)*(n-i+1);
	sum=m*n*(m+1)*(n+1)/4;
	sum2=sum-sum1;
    printf("%d %d",sum1,sum2);
	//system("pause");
	return 0;
}
