#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,A,B,mid,anss,ans,last;
int a[100010];
bool judge(int t)
{
	ans=1;
	last=1;
	for(int i=2;i<=A;i++)
	{
		if(a[i]-a[last]>=t)
		{
			ans++;
			last=i;
		}
	}
	if(ans>=B)
		return 1;
	return 0;
}
int main()
{
	int i;
	int low,high;
	scanf("%d %d",&A,&B);
	for(i=1;i<=A;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+A+1);
	low=1;
	high=a[A]-a[1];
	while(low<=high)
	{
		mid=(low+high)/2;
		if(judge(mid))
		{
			anss=mid;
			low=mid+1;
		}
		else
			high=mid-1;
	}
	printf("%d",anss);
	return 0;
}