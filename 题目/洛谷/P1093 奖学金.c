#include <stdio.h>
#include <stdlib.h>
struct stu
{
	int yu;
    int shu;
    int ying;
    int sum;
    int num;
    
};
int main()
{	
    int n,i,j;
    struct stu a[310],t;
	scanf("%d",&n);
    for(i=1;i<=n;i++)
		{
			scanf("%d %d %d",&a[i].yu,&a[i].shu,a[i].ying);
            sum=sum+a[i].yu+a[i].shu+a[i].ying;
        }
    for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i;j++)
			if(a[j].sum<a[j+1].sum)
            {
				t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
            else if((a[j].sum==a[j+1].sum)&&(a[j].yu<a[j+1].yu))
            {
				t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
            else if((a[j].sum==a[j+1].sum)&&(a[j].yu==a[j+1].yu)&&(a[j].num>a[j+1].num))
            {
				t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
    for(int i=1;i<=n;i++)
		printf("%d %d\n",a[i].id,a[i].sum);
	system("pause");
	return 0;
}
