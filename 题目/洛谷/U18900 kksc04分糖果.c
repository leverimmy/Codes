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
int main()
{
	int q;
    int l,r,i,s,j,count=0;
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
		scanf("%d %d",&l,&r);
        for(j=l;j<=r;j++)
        {
			s=(j+1)/2;
			if(prime(j)==1 && prime(s)==1)
				count++;
        }
        printf("%d\n",count);
    }
	system("pause");
	return 0;
}
