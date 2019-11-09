#include<bits/stdc++.h>
using namespace std;
double ans=0;
int n,m;
int a[101];
int l[101],r[101];
void dfs(int x)
{
	if(x==n)
	{
		int tot=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++)
				if(a[j]>a[i])
					tot++;
		ans+=(double)tot/(1<<m);
		return;
	}
	dfs(x+1);
	swap(a[l[x]],a[r[x]]);
	dfs(x+1);
	swap(a[l[x]],a[r[x]]);
}
signed main()
{
	freopen("inverse.in","r",stdin);
	freopen("inverse.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&l[i],&r[i]);
	dfs(1);
	printf("%.20lf",ans);
	return 0;
}
