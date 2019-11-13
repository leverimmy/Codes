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
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
ll a[500050];
signed main()
{
	freopen("clean.in","r",stdin);
	freopen("clean.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x]++;
		a[y+1]--;
	}
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	int ans(0);
	for(int i=1;i<=n;i++)
		if(!a[i])
			ans++;
	return!printf("%d\n",ans);
}
