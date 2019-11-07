#include<cstdio>
#include<cstring>
#include<cassert>
#include<climits>
#include<cstdlib>
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
int fa[3003];
int find(int x)
{
	if(x==fa[x])
		return x;
	return fa[x]=find(fa[x]);
}
signed main()
{
	freopen("18.in","r",stdin);
	freopen("18.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	int ans(n);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int fx=find(x),fy=find(y);
		if(fx!=fy)
		{
			ans--;
			fa[fx]=fy;
		}
	}
	return!printf("%d\n",ans);
}
