#include <stdio.h>
#include <stdlib.h>
int main()
{
	long long int m,n=0;
    scanf("%lld",&m);
    while(m)
    {
		n=10*n+m%10;
        m=m/10;
    }
    printf("%lld",n);
	//system("pause");
	return 0;
}
