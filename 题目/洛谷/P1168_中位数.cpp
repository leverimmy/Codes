#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

void quicksort(int a[],int left,int right)
{
    int i,j,t;
    int mid;
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

int n;
int a[110010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	quicksort(a,1,n);
	for(int i=1;2*i-1<=n;i=i+1)
		printf("%d\n",a[(i+1)/2]);
	return 0;
}