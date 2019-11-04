#include <stdio.h>
#include <stdlib.h>
struct milk
{
	int dan;
    int num;
};
struct milk a[100],t;
void quicksort(int left,int right)
{
	int i,j,mid;
    i=left;
    j=right;
    mid=a[(left+right)/2].dan;
    do
    {
		while(a[i].dan<mid)
			i++;
		while(a[j].dan>mid)
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
	int i,j,total,n,sum=0,money=0;
    scanf("%d %d",&total,&n);
    for(i=0;i<n;i++)
		scanf("%d %d",&a[i].dan,&a[i].num);
	quicksort(0,n-1);
    i=0;
    do
    {
		sum=sum+a[i].num;
        money=money+a[i].dan*a[i].num;
        i++;
    }while(sum<total);
    printf("%d",money);
	//system("pause");
	return 0;
}
