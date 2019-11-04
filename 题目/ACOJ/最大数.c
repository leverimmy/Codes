#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a<=b&&b<=c) printf("%d",c);
    if(a<=b&&b<a) printf("%d",b);
    if(b<a&&c<a) printf("%d",a);
	system("pause");
	return 0;
}
