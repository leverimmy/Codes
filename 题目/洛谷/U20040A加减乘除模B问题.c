#include <stdio.h>
#include <stdlib.h>
int main()
{
	long long int a,b;
    scanf("%lld %lld",&a,&b);
    if(a+b<0)
		printf("Wrong");
    else
		printf("%lld\n",a+b);
    if(a-b<0)
		printf("Wrong");
    else
		printf("%lld\n",a-b);
    if(a*b<0)
		printf("Wrong");
    else
		printf("%lld\n",a*b);
    if(a/b<0 || b==0)
		printf("Wrong");
    else
		printf("%lld\n",a/b);
    if(a%b<0 || b==0)
		printf("Wrong");
    else
		printf("%lld",a%b);
	system("pause");
	return 0;
}

