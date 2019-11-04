#include <stdio.h>
#include <stdlib.h>
int main()
{
	long long int n,m,t,i;
    long long int sum1=0,sum2=0,sum=0;
    scanf("%lld %lld",&n,&m);
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
    printf("%lld %lld",sum1,sum2);
	system("pause");
	return 0;
}
