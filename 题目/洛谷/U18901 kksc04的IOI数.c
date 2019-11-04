#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int prime(int x)
{
	int k;
    if(x<2)
		return 0;
	for(k=2;k<=sqrt(x);k++)
		if(x%k==0)
			return 0;
	return 1;
}
int ioi(int x)
{
	int r;
	for(r=2;r<=x;r++)
    {
		if(prime(r)==0)
			continue;
        else
		{
			if(x%r==0)
				{
					if(r==2 || r==3 || r==5)
						continue;
					else
						return 0;	
                }
        }
    }
    return 1;
}
int main()
{
	int n,count=0,i=0;
    scanf("%d",&n);
	while(count!=n)
    {
		i++;
		if(ioi(i)==1)
			count++;
    }
    printf("%d",i);
	system("pause");
	return 0;
}
