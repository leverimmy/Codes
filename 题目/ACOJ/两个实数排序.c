#include <stdio.h>
#include <stdlib.h>
void main()
{
	float a,b;
    scanf("%f%f",&a,&b);
    if(a>=b) 
		printf("%f %f",a,b);
    else 
		printf("%f %f",b,a);
	system("pause");
	return 0;
}
