#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
int n,m1,m2,a[1000009],minn=999999999;
using namespace std;
void dfsup(int u,int money) 
{
	if(u==n+1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=a[i+1])
			{
				cnt++;
			}
		}
		if(cnt==n)
			minn=min(minn,money);
		return;
	}
	int kk=a[u];
	if(a[u]<a[u+1] && a[u]<a[u-1])
	{
		a[u]=a[u-1];
		dfsup(u+1,money+m1);
	}
	if(a[u]>a[u+1] && a[u]>a[u-1])
	{
		a[u]=a[u-1];
		dfsup(u+1,money+m2);
	}
	a[u]=kk;
	dfsup(u+1,money);
	a[u]=kk;
	return;
}
void dfsdown(int u,int money) 
{
	if(u==n+1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=a[i+1])
			{
				cnt++;
			}
		}
		if(cnt==n)
			minn=min(minn,money);
		return;
	}
	int kk=a[u];
	if(a[u]<a[u+1] && a[u]<a[u-1])
	{
		a[u]=a[u-1];
		dfsdown(u+1,money+m1);
		a[u]=kk;
	}
	if(a[u]>a[u+1] && a[u]>a[u-1])
	{
		a[u]=a[u-1];
		dfsdown(u+1,money+m2);
		a[u]=kk;
	}
	a[u]=kk;
	dfsdown(u+1,money);
	a[u]=kk;
	return;
}
int main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout); 
	scanf("%d%d%d",&n,&m1,&m2);
	if(n==1)
	{
		printf("0");
		return 0;
	}
	if(n==2)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	a[n+1]=999999999;
	dfsup(1,0);
	a[n+1]=0;
	dfsdown(1,0); 
	printf("%d",minn); 
	return 0;
}

