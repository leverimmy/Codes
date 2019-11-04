#include <stdio.h>
#include <stdlib.h>
int main()
{
	double x,n;
    scanf("%lf",&x);
    if(x<=150)
		n=0.4463*x;
    if((x>150)&&(x<=400))
		n=150*0.4463+(x-150)*0.4663;
    if(x>400)
		n=150*0.4463+250*0.4663+(x-400)*0.5663;
    printf("%.1lf",n);
	//system("pause");
	return 0;
}
