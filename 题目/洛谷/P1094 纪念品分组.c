#include <stdio.h>
#include <stdlib.h>
void quicksort(int a[],int left,int right)
{
	if(left>right)
		return;
    int i,j,t,r;
    i=left;
    j=right;
    t=a[left];
    while(i!=j)
    {
		while(j>=t && i<j)
			j--;
        while(i>=t && i<j)
			i++;
        if(i<j)
		{
			r=a[i];
            a[i]=a[j];
            a[j]=r;
        }
    }
    a[left]=a[i];
    a[i]=t;
    quicksort(a,left,i-1);
    quicksort(a,i+1,right);
    return;
}
int main()
{
	int a[30010]={0},w,n;
    int i,j,t,front,back,count=0;
    scanf("%d\n%d",&w,&n);
    for(i=0;i<n;i++)
		scanf("%d",&a[i]);
    /*for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
        if(a[j]>a[j+1])
        {
			t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
        }*/
    quicksort(a,0,n-1);
    front=0;
    back=n-1;
    while(front<=back)
    {
		if(a[front]+a[back]<=w)
		{
			count++;
            back--;
            front++;
        }
        else
        {
			count++;
            back--;
        }
    }
    printf("%d",count);
	system("pause");
	return 0;
}
