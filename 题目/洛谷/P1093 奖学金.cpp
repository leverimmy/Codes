#include<stdio.h>
struct jxj{
	int yw;
	int sx;
	int yy;
	int sum;
	int id;
};
int main()
{	struct jxj a[500],temp;
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].yw,&a[i].sx,&a[i].yy);
		a[i].sum=a[i].yw+a[i].sx+a[i].yy;
                a[i].id=i;
	}
	for(i=1;i<n;i++)
		for(j=1;j<=n-i;j++)
		{if(a[j].sum<a[j+1].sum)
			{temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
			}
		else if(a[j].sum==a[j+1].sum&&a[j].yw<a[j+1].yw)
			{temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
			}
		else if(a[j].sum==a[j+1].sum&&a[j].yw==a[j+1].yw&&a[j].id>a[j+1].id)
			{temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
			}
		}
		for(i=1;i<=5;i++)
		printf("%d %d\n",a[i].id,a[i].sum);
		return 0;
}