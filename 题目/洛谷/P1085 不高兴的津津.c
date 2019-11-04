#include <stdio.h>
#include <stdlib.h>
struct chengdu
{
	int num;
    int sch;
    int mum;
    int sum;
};
int main()
{
	struct chengdu a[7],t;
    int i,j;
    for(i=0;i<7;i++)
    {
		scanf("%d",&a[i].sch);
        scanf("%d",&a[i].mum);
        a[i].sum=a[i].sch+a[i].mum;
        a[i].num=i+1;
    }
    for(i=0;i<6;i++)
		for(j=0;j<6-i;j++)
		{
			if(a[j].sum<a[j+1].sum)
				{
					t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
			else if((a[j].sum==a[j+1].sum)&&(a[j].num>a[j+1].num))
				{
					t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
		}
	if(a[0].sum>8)
		printf("%d",a[0].num);
    else
		printf("0");
	//system("pause");
	return 0;
}
