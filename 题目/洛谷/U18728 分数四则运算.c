#include <stdio.h>
#include <stdlib.h>
long long int min(long long int x,long long int y)
{
	if(x<=y)
		return x;
    else
		return y;
}
int main()
{
	long long int n1,m1,n2,m2,i,fenzi,fenmu;
    char c;
    scanf("%lld %lld\n%c\n%lld %lld",&n1,&m1,&c,&n2,&m2);
    if(c=='+')
    {
		fenzi=n1*m2+n2*m1;
        fenmu=m1*m2;
        for(i=1;i<=min(fenzi,fenmu);i++)
        {
			if(fenzi%i==0 && fenmu%i==0)
			{
				fenzi=fenzi/i;
                fenmu=fenmu/i;
            }
        }
        printf("%lld %lld",fenzi,fenmu);
    }
    else if(c=='-')
    {
		fenzi=n1*m2-n2*m1;
        fenmu=m1*m2;
        for(i=1;i<=min(fenzi,fenmu);i++)
        {
			if(fenzi%i==0 && fenmu%i==0)
			{
				fenzi=fenzi/i;
                fenmu=fenmu/i;
            }
        }
        printf("%lld %lld",fenzi,fenmu);
    }
    else if(c=='*')
    {
		fenzi=n1*n2;
        fenmu=m1*m2;
        for(i=1;i<=min(fenzi,fenmu);i++)
        {
			if(fenzi%i==0 && fenmu%i==0)
			{
				fenzi=fenzi/i;
                fenmu=fenmu/i;
            }
        }
        printf("%lld %lld",fenzi,fenmu);
    }
    else if(c=='/')
    {
		fenzi=n1*m2;
        fenmu=m1*n2;
        for(i=1;i<=min(fenzi,fenmu);i++)
        {
			if(fenzi%i==0 && fenmu%i==0)
			{
				fenzi=fenzi/i;
                fenmu=fenmu/i;
            }
        }
        printf("%lld %lld",fenzi,fenmu);
    }
	system("pause");
	return 0;
}
