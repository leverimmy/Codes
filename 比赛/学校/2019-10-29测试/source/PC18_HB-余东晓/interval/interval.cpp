#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<climits>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<complex>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f
#define ll long long
struct data
{
	int v,id; 
}dt[400040];
bool Dwv(data x,data y)
{
	return x.v<y.v;
}
bool Did(data x,data y)
{
	return x.id<y.id;
}
struct node
{
	int l,r,id;
}a[200020];
bool operator <(node x,node y)
{
	if(x.r==y.r)
		return x.id<y.id;
	return x.r>y.r;
}
std::map<int,int>m;
std::vector<int>ans;
signed main()
{
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	int n,tot(0);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&dt[i*2-1].v,&dt[i*2].v);
	for(int i=1;i<=n<<1;i++)
		dt[i].id=i;
	std::sort(dt+1,dt+(n<<1)+1,Dwv);
	for(int i=1;i<=n<<1;i++)
	{
		if(!m[dt[i].v])
			m[dt[i].v]=++tot;
		dt[i].v=m[dt[i].v];
	}
	std::sort(dt+1,dt+(n<<1)+1,Did);
	for(int i=1;i<=n;i++)
	{
		a[i].l=dt[(i<<1)-1].v;
		a[i].r=dt[i<<1].v;
		a[i].id=i;
	}
	std::sort(a+1,a+n+1);
	int u(INF);
	for(int i=1;i<=n;i++)
		if(u>a[i].r)
		{
			ans.push_back(a[i].id);
			u=a[i].l;
		}
	printf("%d\n",ans.size());
	std::sort(ans.begin(),ans.end());
	for(int i=0;i<(int)ans.size();i++)
		printf("%d ",ans[i]);
	return puts(""),0;
}
