#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,a[100],i,sum=0;
    double aver;
    scanf("%d",&n);
    for(i=0;i<=100;i=i+1)
		a[i]=0;
	for(i=0;i<=100;i=i+1)
		scanf("%d",&a[i]);
    for(i=0;i<=100;i=i+1)
		sum=sum+a[i];
	aver=1.0*sum/n;
    printf("%.2lf",aver);
	//system("pause");
	return 0;
}
