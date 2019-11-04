#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
struct node
{
	int x,y;
	ll cost;
	bool operator<(const node& t)
	const
	{
		return cost>t.cost;
	}
}a[maxn];
int n,m,tot,par[maxn];
vector<int>G[maxn];
void init()
{
	for(int i=1;i<=n*m;i++)
	G[i].clear(),par[i]=i;
	tot=0;
}
void add(int u,int v,int cost)
{
	a[++tot].x=u;
	a[tot].y=v;
	a[tot].cost=cost;
}
int find(int x)
{
	if(par[x]!=x)
	par[x]=find(par[x]);
	return par[x];
}
void kruskal()
{
	sort(a+1,a+1+tot);
	int sum=0;
	for(int i=1;i<=tot;i++)
	{
		int u=find(a[i].x);
		int v=find(a[i].y);
		if(u!=v)
		{
			par[u]=v;
			G[a[i].x].push_back(a[i].y);
			G[a[i].y].push_back(a[i].x);
			sum++;
		}
		if(sum==n*m-1)break;
	}
}
int f[maxn],L[maxn],anc[maxn][20]; 
void dfs(int u,int fa,int deep)//LCA
{
	f[u]=fa;
	L[u]=deep;
	for(int i=0;i<G[u].size();i++)
	if(G[u][i]!=fa)dfs(G[u][i],u,deep+1);
}
void pre()
{
	memset(anc,0,sizeof(anc));
	for(int i=1;i<=n*m;i++)
	{
		anc[i][0]=f[i];
		for(int j=1;(1<<j)<n*m;j++)
		anc[i][j]=-1;
	}
	for(int j=1;(1<<j)<n*m;j++)
	for(int i=1;i<=n*m;i++)
	if(anc[i][j-1]!=-1)
	{
		int t=anc[i][j-1];
		anc[i][j]=anc[t][j-1];
	}
}
int query(int p,int q)
{
	int log,i,ans=0;
	if(L[p]<L[q])swap(p,q);
	for(log=1;(1<<log)<=L[p];log++);log--;
	for(i=log;i>=0;i--)
	if(L[p]-(1<<i)>=L[q])
	{
		ans+=(1<<i);
		p=anc[p][i];
	}
	if(p==q)return ans;
	for(i=log;i>=0;i--)
	if(anc[p][i]!=-1&&anc[p][i]!=anc[q][i])
	{
		ans+=2*(1<<i);
		p=anc[p][i];
		q=anc[q][i];
	}
	ans+=2;
	return ans;
}
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	char s1[2],s2[2];
	ll c1,c2;
	while(~scanf("%d%d",&n,&m))
	{
		init();
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int u=(i-1)*m+j,v1=u+m,v2=u+1;
			scanf("%s%lld%s%lld",s1,&c1,s2,&c2);
			if(s1[0]=='D')add(u,v1,c1);
			if(s2[0]=='R')add(u,v2,c2);
		}
		kruskal();
		dfs(1,-1,0);
		pre();
		int q,x1,x2,y1,y2;
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			int u=(x1-1)*m+y1;
			int v=(x2-1)*m+y2;
			printf("%d\n",query(u,v));
		}
	}
}
