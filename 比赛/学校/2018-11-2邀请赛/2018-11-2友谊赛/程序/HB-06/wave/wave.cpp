#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
	int x,y;
}w[50001],q[50001];
bool cmp(node a,node b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y>b.y;
}
int main()
{
	freopen("wave.in","r",stdin);
	freopen("wave.out","w",stdout);
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&w[i].x,&w[i].y);
	q[1].x=0;
	q[1].y=10000001;
	int tail=1;
	for(int i=n;i>=1;i--)
	{
		while(q[tail].x<w[i].x&&q[tail].y<w[i].y)
			tail--;
		sort(q+1,q+tail+1,cmp);
		int l=1,r=tail+1;
		while(l+1<r)
		{
			int mid=(l+r)/2;
			if(q[mid].y>w[i].y)
				l=mid;
			else
				r=mid;
		}
		if(q[l].x>w[i].x)
			continue;
		else
		{
			ans+=w[i].x-q[l].x;
			q[++tail].x=w[i].x;
			q[tail].y=w[i].y;
		}
	}
	memset(q,0,sizeof(q));
	for(int i=1;i<=n;i++)
		swap(w[i].x,w[i].y);
	q[1].x=0;
	q[1].y=10000001;
	tail=1;
	for(int i=n;i>=1;i--)
	{
		while(q[tail].x<w[i].x&&q[tail].y<w[i].y)
			tail--;
		sort(q+1,q+tail+1,cmp);
		int l=1,r=tail+1;
		while(l+1<r)
		{
			int mid=(l+r)/2;
			if(q[mid].y>w[i].y)
				l=mid;
			else
				r=mid;
		}
		if(q[l].x>w[i].x)
			continue;
		else
		{
			ans+=w[i].x-q[l].x;
			q[++tail].x=w[i].x;
			q[tail].y=w[i].y;
		}
	}		
	printf("%lld",ans);
	return 0;
}
/*
3
1 4
4 1
3 3
*/