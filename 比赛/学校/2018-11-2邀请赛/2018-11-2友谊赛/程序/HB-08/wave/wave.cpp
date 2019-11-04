#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<queue>
#include<vector>
#include<map>
#define ll long long
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
struct node
{
	ll x,y;
}a[500001];
int main()
{
	freopen("wave.in","r",stdin);
	freopen("wave.out","w",stdout);
	ll n=read();
	for(ll i=1;i<=n;i++)
	{
		a[i].x=read(),a[i].y=read();
	}
	ll ans=0;
	for(ll i=n;i>=1;i--)
	{
		ll nex=0,ney=0,maxx1=0,maxy2=0;
		for(ll j=n;j>i;j--)
		{
			if(a[j].y<=a[i].y&&a[j].y>ney&&a[j].x>a[i].x)
				ney=a[j].y;
			if(a[j].x<=a[i].x&&a[j].x>nex&&a[j].y>a[i].y)
				nex=a[j].x;
			if(a[j].x>maxx1)
			{
				maxx1=a[j].x;
			}
			if(a[j].y>maxy2)
			{
				maxy2=a[j].y;
			}
		}
		if(maxx1<a[i].x&maxy2<a[i].y&&(nex!=0)&&(ney!=0))
		{
			ans+=a[i].x+a[i].y;
			continue;
		}
		ans+=a[i].x-nex+a[i].y-ney;
	}
	cout<<ans;
	return 0;
}

