#include <stdio.h>
#include <stdlib.h>
int main()
{
	int time,i,g,s,b,goldt,silvert,bronzet,total;
    i=0;
    goldt=0;
    silvert=0;
    bronzet=0;
    total=0;
    scanf("%d",&time);
    while (i<time)
		{
			scanf("%d %d %d",&g,&s,&b);
            goldt=goldt+g;
            silvert=silvert+s;
            bronzet=bronzet+b;
            i=i+1;
        }
    total=goldt+silvert+bronzet;
    printf("%d %d %d %d",goldt,silvert,bronzet,total);
	//system("pause");
	return 0;
}
