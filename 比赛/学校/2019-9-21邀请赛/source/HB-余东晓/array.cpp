#include<cstdio>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<cstring>
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
int a[100010],f[100010];
struct qus
{
	int id,x,y,ans;
}dt[100010];
bool operator <(qus x,qus y)
{
	return x.y<y.y;
}
bool cmp(qus x,qus y)
{
	return x.id<y.id;
}
signed main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int m;
	scanf("%d",&m);
	if(n<=100&&m<=100)
	{
		while(m--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			int ans(0);
			while(x<=n)
			{
				x+=a[x]+y;
				ans++;
			}
			printf("%d\n",ans);
		}
		return 0;
	}
	f[n]=0;
	for(int i=n;i>=1;i--)
		if(i+a[i]<=n)
			f[i]=f[i+a[i]]+1;
	for(int i=1;i<=m;i++)
	{
		dt[i].id=i;
		scanf("%d%d",&dt[i].x,&dt[i].y);
	}
	std::sort(dt+1,dt+m+1);
	if(!dt[m].y)
	{
		for(int i=1;i<=m;i++)
			dt[i].ans=f[dt[i].x];
		sort(dt+1,dt+m+1,cmp);
		for(int i=1;i<=m;i++)
			printf("%d\n",dt[i].ans);
	}
	
	return 0;
}
