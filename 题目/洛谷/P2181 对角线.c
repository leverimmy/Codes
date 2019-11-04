#include <stdio.h>
#include <stdlib.h>
int main()
{
	unsigned long long int n,k;
    scanf("%llu",&n);
    k=n*(n-1)/2*(n-2)/3*(n-3)/4;
    printf("%llu",k);
	system("pause");
	return 0;
}
