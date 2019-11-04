#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int prime(int x)
{
	int i;
	if(x<2)
		return 0;
    else
	{
		for(i=2;i<=sqrt(x);i++)
			if(x%i==0)
				return 0;
    }
    return 1;
}
int main()
{
	int n,i,j,k;
    int count[100000]={0};
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
		j=i;
        for(k=1;k<=i;k++)
			while((j%k==0) && (prime(k)==1) && j>1)
			{
            	count[k]++;
                j=j/k;
            }
    }
    for(i=0;i<=n;i++)
		if(count[i]!=0)
			printf("%d %d\n",i,count[i]);
	system("pause");
	return 0;
}
