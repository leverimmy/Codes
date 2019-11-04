#include<iostream>
#include<cstdio>
using namespace std;
int n,m,zong[100001],heng[100001];
long long ans;
int main()
{
	freopen("rush.in","r",stdin);
	freopen("rush.out","w",stdout);
	int i,j,x,y;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		zong[y]=1;
		heng[x]=1;
	}
	x=0;
	y=0;
	for(i=1;i<=n;i++)
	{
		if(!zong[i])
			x++;
		if(!heng[i])
			y++;
	}
	ans=x+y;
	if(n%2&&!heng[n/2+1]&&!zong[n/2+1])
		ans--;
	cout<<ans;
	return 0;
}
