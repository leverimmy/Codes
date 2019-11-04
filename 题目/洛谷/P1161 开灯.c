#include <stdio.h>
#include <stdlib.h>
int light[1110000];
int main()
{
    int i,j,t,n,k;
    double a;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
		scanf("%lf %d",&a,&t);
		for(j=1;j<=t;j++)
		{
        	k=j*a;
            light[k]=!light[k];
        }
    }
    for(i=0;i<1110000;i++)
		if(light[i]==1)
			printf("%d",i);
	system("pause");
	return 0;
}
