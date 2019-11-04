#include <stdio.h>
#include <stdlib.h>
void quicksort(int a[],int left,int right)
{
	int i,j,mid,t;
    i=left;j=right;
    mid=a[(left+right)/2];
    do
    {
		while(a[i]<mid)
			i++;
        while(a[j]>mid)
			j++;
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
		quicksort(a,left,j);
    if(right>i)
		quicksort(a,i,right);
}
int main()
{
	int n,m,i,max=-100,num=100,price;
    int a[100000];
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
		scanf("%d",&a[i]);
    quicksort(a,0,m-1);
    for(i=0;i<m;i++)
		printf("%d\n",a[i]);
    system("pause");
    for(i=0;i<m;i++)
    {
		price=a[i]*(m-i);
        if(price>max)
		{	
            max=price;
            num=i;
        }
    }
    printf("%d %d",num,max);
	system("pause");
	return 0;
}
