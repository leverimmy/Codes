#include <stdio.h>
#include <stdlib.h>
int main()
{
	int r,t,b,c;
    int a[3],i,j;
    int n=3;
    scanf("%d %d %d",&r,&b,&c);
	a[0]=r;a[1]=b;a[2]=c;
    for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(a[j]>a[j+1])
			{
				t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
    r=a[0];b=a[1];c=a[2];
	//printf("%d %d %d",r,b,c);
    i=1;
    while(r%i==0 && c%i==0)
    {
		r=r/i;
        c=c/i;
        i++;
    }
    printf("%d/%d",r,c);
	system("pause");
	return 0;
}
