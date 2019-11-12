#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<climits>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<stack>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
int a[101],cnt[101];
signed main()
{
	freopen("zuma.in","r",stdin);
	freopen("zuma.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	if(k==1)
		return puts("0"),0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		cnt[a[i]]++;
	int ans(0);
	for(int i=1;i<=100;i++)
		if(cnt[i]&&cnt[i]<k)
			ans+=k-cnt[i];
	return!printf("%d\n",ans);
}
