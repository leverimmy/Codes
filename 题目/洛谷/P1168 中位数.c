#include <stdio.h>
#include <stdlib.h>
void quicksort(long long int a[],int left,int right)
{
	int i,j,t;
    long long int mid;
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
	long long int a[100010];
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
    quicksort(a,0,n-1);
    for(i=1;i<=n;i=i+2)
		printf("%lld\n",a[i/2]);
	system("pause");
	return 0;
}
