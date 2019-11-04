#include <stdio.h>
#include <stdlib.h>
struct kaoshi
{
	int st;
    int et;
}a[100000],t;
void quick_sort(int left,int right)
{
	int i,j,mid;
	i=left;
	j=right;
	mid=a[(left+right)/2].et;
	do
	{
		while(a[i].et<mid)
			i++;
		while(a[j].et>mid)
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
	if(left<j)	quick_sort(left,j);
	if(i<right)	quick_sort(i,right);
}
int main()
{
	int n,i,j,count=1,maxi=0;
    int q[100000];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
		{
			scanf("%d %d",&a[i].st,&a[i].et);
            a[i].len=a[i].et-a[i].st;
        }
    quick_sort(1,n);
    maxi=a[1].et;
    j=1;
    while(j<=n)
    {
		j++;
		if(a[j].st>=maxi)
		{	
            count++;
			maxi=a[j].et;
        }
    }
    printf("%d",count);
	system("pause");
	return 0;
}
