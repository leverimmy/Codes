#include<bits/stdc++.h>
using namespace std;
int a[100001],sum[100001],rem[100001];
signed main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),sum[a[i]]++;
	for(int i=n;i>1;i--)
	{
		if(sum[i]>sum[i-1])
		{
			printf("-1");
			return 0;
		}
	}
	printf("%d\n",sum[1]);
	for(int i=1;i<=n;i++)
	{
		++rem[a[i]];
		printf("%d ",rem[a[i]]);
	}
	return 0;
}
