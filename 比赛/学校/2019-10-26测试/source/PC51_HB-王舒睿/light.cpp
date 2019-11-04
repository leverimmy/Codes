#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int l[100001],r[100001],p[100001],v[100001];
int main()
{
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	int n,m;
	int a[100010];
	int b;
	cin>>n>>m;
	for(b=1;b<=n;b++)
		cin>>a[b];
	int x=1;
	for(b=1;b<=m;b++)
	{
		cin>>l[b]>>r[b]>>p[b]>>v[b];
		if(p[b]!=p[1])
			x=0;
	}
	if(x==1)
	{
		for(b=1;b<=n;b++)
			a[b]=a[b]%p[1];
		for(b=1;b<=m;b++)
		{
			int ans=0;
			for(int d=l[m];d<=r[m];d++)
			{
				if(a[d]==v[m])
					ans++;
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	else
	{
		for(b=1;b<=m;b++)
		{
			int ans=0;
			for(int d=l[b];d<=r[b];d++)
			{
				if(a[d]%p[b]==v[b])
					ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
