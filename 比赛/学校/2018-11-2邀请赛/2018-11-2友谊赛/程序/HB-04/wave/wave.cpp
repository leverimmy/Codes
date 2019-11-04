#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<cstdlib>
#include<algorithm>
#include<complex>
#include<iostream>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
struct node
{
	int x,y;
	node(){}
	node(int x,int y):x(x),y(y){}
}a[1000010];
int n;
int ans(0);
int xmx(0);
int ymx(0);
int main()
{
	freopen("wave.in","r",stdin);
	freopen("wave.out","w",stdout);
	a[0].x=0;
	a[0].y=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i].y>ymx&&a[i].x>xmx)
		{
			ans+=a[i].x;
			ans+=a[i].y;
		}
		else if(a[i].x>xmx)
		{
			ans+=a[i].x-xmx+a[i].y;
		}
		else
		{
			ans+=a[i].y-ymx+a[i].x;
		}
		xmx=max(a[i].x,xmx);
		ymx=max(a[i].y,ymx);
	}
	printf("%d",ans);
	return 0;
}