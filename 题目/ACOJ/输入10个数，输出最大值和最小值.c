#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[10],big,small,i;
    for(i=0;i<10;i++)
		scanf("%d",&a[i]);
    big=a[0];
    small=a[0];
    for(i=0;i<10;i++)
		{
        if(big<a[i])
			big=a[i];
        if(small>a[i])
			small=a[i];
        }
    printf("%d %d",big,small);
	system("pause");
	return 0;
}
