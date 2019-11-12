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
int fa[100010],size[100010];
int find(int x)
{
	if(x==fa[x])
		return x;
	return fa[x]=find(fa[x]);
}
struct data
{
	int x,y;
	ll g,d;
}a[100010];
bool operator <(data x,data y)
{
	return (x.g==y.g)?x.d<y.d:x.g<y.g;
}
struct node
{
	int id,v;
	node(){}
	node(int id,int v):id(id),v(v){}
};
std::queue<node>q;
std::vector<int>vec[100010];
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy)
		return;
	fa[fx]=fy;
	size[fy]+=size[fx];
}
signed main()
{
	freopen("pay.in","r",stdin);
	freopen("pay.out","w",stdout);
	int n,m;
	ll gcost,dcost,ans;
	memset(&ans,INF,sizeof(ll));
	scanf("%d%d%lld%lld",&n,&m,&gcost,&dcost);
	for(int i=1;i<=m;i++)
		scanf("%d%d%lld%lld",&a[i].x,&a[i].y,&a[i].g,&a[i].d);
	a[0].g=-INF;
	a[0].d=-INF;
	std::sort(a+1,a+m+1);
	for(int i=1;i<=m;i++)
		if(a[i].g!=a[i-1].g)
			q.push(node(i,a[i].g));
	for(int i=1;i<=n;i++)
		vec[a[i].d].push_back(i);
	while(!q.empty())
	{
		node u=q.front();
		q.pop();
		ll mix(INF),mx(0);
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
			size[i]=1;
		}
		for(int i=1;i<=u.id;i++)
		{
			mix=std::min(mix,a[i].d);
			mx=std::max(mx,a[i].d);
		}
		for(ll i=mix;i<=mx;i++)
			for(int j=0;j<(int)vec[i].size();j++)
			{
				if(vec[i][j]>u.id)
					continue;
				merge(a[vec[i][j]].x,a[vec[i][j]].y);
				int p=find(1);
				if(size[p]==n)
					ans=std::min(ans,i*dcost+u.v*gcost);
			}
	}
	if(ans>1e15)
		ans=-1;
	return!printf("%lld\n",ans);
}