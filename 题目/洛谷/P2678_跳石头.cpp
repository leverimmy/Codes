#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int low,high,mid,ans,n,l,m,i;
int a[1000010];
bool judge(int x)
{
	int total=0;
	int next=0;
	int now=0;
	while(next<m+1)
	{
		next++;
		if(a[next]-a[now]<x)
			total++;
		else
			now=next;
	}
	if(total>n)
		return false;
	return true;
}
int main()
{
	scanf("%d %d %d",&l,&m,&n);
	for(i=1;i<=m;i++)
		scanf("%d",&a[i]);
	a[m+1]=l;
	low=1;
	high=l;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(judge(mid))
		{
			ans=mid;
			low=mid+1;
		}
		else
			high=mid-1;
	}
	printf("%d",ans);
	return 0;
}