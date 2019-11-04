#include <iostream>
#include <cstdio>
#include <algorithm>
#define rgi register int
using namespace std;
int n,m,a[15],ans[120][15],sum[300],t[300],indx;
inline bool check()
{
	int ind=0;
	for(rgi i=1;i<=n;++i)
		for(rgi j=i+1;j<=n;++j)
			t[++ind]=a[i]+a[j];
	sort(t+1,t+m+1);
	for(rgi i=1;i<=m;++i)
		if(sum[i]!=t[i])
			return 0;
	return 1;
}
void dfs(int pos)
{
	if(pos==n+1)
	{
		if(check())
		{
			++indx;
			for(rgi i=1;i<=n;++i)
			{
				//cout<<a[i]<<" ";
				ans[indx][i]=a[i];
			}
			//cout<<endl;
		}
		return;
	}
	for(rgi i=a[pos-1]+1;i<=13;++i)
	{
		a[pos]=i;
		dfs(pos+1);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	cin>>n;
	m=(n*(n-1))>>1;
	for(rgi i=1;i<=m;++i)
		cin>>sum[i];
	sort(sum+1,sum+m+1);
	dfs(1);
	cout<<indx<<endl;
	for(rgi i=indx;i;--i)
	{
		for(rgi j=1;j<=n;++j)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
