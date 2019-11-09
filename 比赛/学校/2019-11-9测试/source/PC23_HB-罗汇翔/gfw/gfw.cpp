#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[200010];
int f[200010][2];
int ans;
int main()
{
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[i-1])f[i][0]=f[i-1][0]+1;
		else f[i][0]=1;
		for(int j=i;j>=i-f[i][0]+1;j--)
		{
			for(int k=1;k<=j-2;k++)
			{
				if(a[j]>a[k])f[i][1]=max(f[i][1],i-j+1+f[k][0]);
			}
		}
		ans=max(ans,f[i][0]);
		ans=max(ans,f[i][1]);
	}
	cout<<ans<<endl;
	return 0;
}
