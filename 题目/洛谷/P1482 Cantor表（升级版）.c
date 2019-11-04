#include <stdio.h>
#include <stdlib.h>
int min(int a,int b)
{
	if(a>=b)
		return b;
    else
		return a;
}
int main()
{
	int a,b,c,d,fenmu,fenzi,i;
    scanf("%d/%d",&a,&c);
    scanf("%d/%d",&b,&d);
    fenmu=a*b;
    fenzi=c*d;
    for(i=2;i<=min(fenzi,fenmu);i++)
    {
		while(fenzi%i==0 && fenmu%i==0)
		{
			fenzi=fenzi/i;
            fenmu=fenmu/i;
        }
    }
    printf("%d %d",fenzi,fenmu);
	system("pause");
	return 0;
}
