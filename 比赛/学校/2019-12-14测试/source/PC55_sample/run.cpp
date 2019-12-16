#include <bits/stdc++.h>
#define rgi register int 
using namespace std;
const int maxn=200005;
const int maxm=600005;
int n,m;
struct edge
{
	int u,v,w;
}a[maxm];
int u[maxm],v[maxm],w[maxm],fst[maxn],nxt[maxm];
int f[maxn],indx;
int t,q,d[maxn],dp[maxn][25],dis[maxn][25];
bool book[maxn];
inline bool cmp(edge p,edge q)
{
	return p.w<q.w;
}
inline int getf(int x)
{
	if(x==f[x])
		return x;
	f[x]=getf(f[x]);
	return f[x];
}
inline void addedge(int p,int q,int r)
{
	u[++indx]=p,v[indx]=q,w[indx]=r;
	nxt[indx]=fst[p],fst[p]=indx;
}
void dfs(int x)
{
	book[x]=1;
	for(rgi i=fst[x];i;i=nxt[i])
	{
		int y=v[i];
		if(book[y])
			continue;
		d[y]=d[x]+1;
		dp[y][0]=x,dis[y][0]=w[i];
		dfs(y);
	}
}
int lca(int x,int y)
{
	if(d[x]<d[y])
		swap(x,y);
	int ans=0;
	for(rgi i=t;i>=0;--i)
		if(d[dp[x][i]]>=d[y])
		{
			ans=max(ans,dis[x][i]);
			x=dp[x][i];
		}
	if(x==y)
		return ans;
	for(rgi i=t;i>=0;--i)
		if(dp[x][i]!=dp[y][i])
		{
			ans=max(ans,max(dis[x][i],dis[y][i]));
			x=dp[x][i],y=dp[y][i];
		}
	return max(ans,max(dis[x][0],dis[y][0]));
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>n>>m;
	t=log(n)/log(2)+1;
	for(rgi i=1;i<=m;++i)
		cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+m+1,cmp);
	for(rgi i=1;i<=n;++i)
		f[i]=i;
	for(rgi i=1;i<=m;++i)
	{
		int f1=getf(a[i].u),f2=getf(a[i].v);
		if(f1==f2)
			continue;
		f[f1]=f2;
		addedge(a[i].u,a[i].v,a[i].w);
		addedge(a[i].v,a[i].u,a[i].w);
	}
	d[1]=1;
	dfs(1);
	for(rgi i=1;i<=t;++i)
		for(rgi j=1;j<=n;++j)
		{
			dp[j][i]=dp[dp[j][i-1]][i-1];
			dis[j][i]=max(dis[j][i-1],dis[dp[j][i-1]][i-1]);
		}
	for(cin>>q;q;--q)
	{
		int x,y;
		cin>>x>>y;
		cout<<lca(x,y)<<endl;
	}
	return 0;
}

