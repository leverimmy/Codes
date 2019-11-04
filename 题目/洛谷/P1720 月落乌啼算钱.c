#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	double sum=0;
    int n;
    scanf("%d",&n);
	sum=(pow(((1+sqrt(5))/2),n)+pow(((1-sqrt(5))/2),n))/sqrt(5);
    if(n==0)
		sum=0;
	printf("%.2lf",sum);
	system("pause");
	return 0;
}
