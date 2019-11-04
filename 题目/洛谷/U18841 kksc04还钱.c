#include <stdio.h>
#include <stdlib.h>
struct peo
{
	int money;
    int qua;
};
int main()
{
	int x,n,i,sum=0,j;
    struct peo r[100],t;
    scanf("%d %d",&x,&n);
    for(i=0;i<n;i++)
	{
		scanf("%d %d",&r[i].money,&r[i].qua);
    }
    for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			{
				if(r[j].qua < r[j+1].qua)
				{
					t=r[j];
                    r[j]=r[j+1];
                    r[j+1]=t;
                }
				else if((r[j].qua == r[j+1].qua)&&(r[j].money > r[j+1].money))
                {
					t=r[j];
                    r[j]=r[j+1];
                    r[j+1]=t;
                }
            }
	for(i=0;i<n;i++)
    {
		if(x>=r[i].money)
        {
			x=x-r[i].money;
            sum=sum+r[i].qua;
        }
    }
    printf("%d",sum);
	system("pause");
	return 0;
}
