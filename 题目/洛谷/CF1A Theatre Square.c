#include <stdio.h>
#include <stdlib.h>
int main()
{
	long long int n,m,a,width=0,length=0,sum=0;
    scanf("%lld %lld %lld",&n,&m,&a);
    if(n%a==0)
		length=n/a;
    else
		length=n/a+1;
    //printf("%d",length);
	if(m%a==0)
		width=m/a;
    else
		width=m/a+1;
    sum=width*length;
    printf("%lld",sum);
	system("pause");
	return 0;
}
