#include <stdio.h>
#include <stdlib.h>
struct kaoshi
{
	int st;
    int et;
    int len;
}a[100000],t;
void quick_sort(int left,int right)
{
	int i,j,mid;
	i=left;
	j=right;
	mid=a[(left+right)/2].len;
	do
	{
		while(a[i].len<mid)
			i++;
		while(a[j].len>mid)
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
	int n,i,j,count=1;
    int q[100000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
		{
			scanf("%d %d",&a[i].st,&a[i].et);
            a[i].len=a[i].et-a[i].st;
        }
    /*for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
			if(a[j].len>a[j+1].len)
				{
					t=a[j];
                    a[j]=a[j+1];
					a[j+1]=t;
                }*/
    quick_sort(0,n-1);
    for(i=0;i<n;i++)
		if(a[i].et>a[i+1].st)
			continue;
		else
			count++;
    printf("%d",count);
	system("pause");
	return 0;
}
