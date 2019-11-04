#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int M=100005;
int n,m,a[M],l,r,p,v,cnt[M];
int main()
{
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>l>>r>>p>>v;
		for(int j=l;j<=r;j++)
		{
			if(a[j]%p==v)
			{
				cnt[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<endl;
	}
	return 0;
}
