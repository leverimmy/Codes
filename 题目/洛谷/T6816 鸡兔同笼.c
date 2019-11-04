#include <stdio.h>
#include <stdlib.h>
int main()
{
	int m,n,tou,tui;
    scanf("%d %d",&tou,&tui);
    m=(tui-2*tou)/2;
    n=tou-m;
    printf("%d %d",m,n);
	system("pause");
	return 0;
}
