#include  <bits/stdc++.h>
using namespace std;
int n,p,m,k,ans,f[100005],a[100005];
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=n;i>=1;i--)
	{
		p=i+a[i];
		if (p>n) f[i]=1; else f[i]=f[p]+1;
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		ans=0;
		scanf("%d%d",&p,&k);
		if (k<=100&&k>0) 
		{
			while (p<=n)
			{
				p=p+a[p]+k;
				ans++;
			}
			printf("%d\n",ans);
		}
		if (k==0)
		{
			printf("%d\n",f[p]);
		}
	}
	return 0;
}
		
