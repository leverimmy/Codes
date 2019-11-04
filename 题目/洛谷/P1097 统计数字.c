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
			j--;
        if(i<=j)
        {
			t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++;j--;
        }
    }while(i<=j);
    if(left<j)
		quicksort(a,left,j);
    if(right>i)
		quicksort(a,i,right);
}
int main()
{
	int a[1110000];
    int i,n,count=1;
    scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
    {
		if(a[i+1]==a[i])
			count++;
		else
		{
			printf("%d %d\n",a[i],count);
            count=1;
        }
    }
	system("pause");
	return 0;
}
