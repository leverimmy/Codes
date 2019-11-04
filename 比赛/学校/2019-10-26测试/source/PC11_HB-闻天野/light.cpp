#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;
int a[10007],l[10007],r[10007],p[10007],v[10007],ans[10007];
int main()
{
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i]>>p[i]>>v[i];
	}
	for(int i=1;i<=m;i++)
    {
    	for(int j=1;j<=n;j++)
	    {
		    if(a[i]>=l[j]&&a[i]<=r[j])
		    {
		    	if(a[i]%p[j]==v[j])
		    	{
		    		ans[j]++;
				}
			}
	    }
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
