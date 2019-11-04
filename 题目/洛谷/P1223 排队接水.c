#include <stdio.h>
#include <stdlib.h>
struct shui
{
	int num;
    int time;
};
struct shui a[10000];
void quicksort(int left,int right)
{
	struct shui t;
	int i,j;
    int mid;
    mid=a[(left+right)/2].time;
    i=left,j=right;
    do
    {
		while(a[i].time<mid)
			i++;
        while(a[j].time>mid)
			j--;
        if(i<=j)
        {
			t=a[i];
            a[i]=a[j];
            a[j]=t;
			i++;
            j--;
        }
    }while(i<=j);
    if(left<j)
		quicksort(left,j);
	if(right>i)
		quicksort(i,right);
}
int main()
{
	int i,n;
    long long int sum=0;
    double aver;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
	{
    	scanf("%d",&a[i].time);
        a[i].num=i;
    }
    quicksort(1,n);
    for(i=1;i<=n;i++)
    {
		printf("%d ",a[i].num);
        sum=sum+(n-i)*a[i].time;
    }
    printf("\n");
    aver=sum/1.0/n;
    printf("%.2lf",aver);
	system("pause");
	return 0;
}
