#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge
{
	int to,w;
	edge(int x1=0,int x2=0){to=x1,w=x2;}
};
vector<edge>e[100001];
int fa[100001];
int vis[100001],dis[100001],dis2[100001];
struct cmp
{
	bool operator()(int a,int b){return dis[a]>dis[b];}
};
void spfa(int st)
{
	priority_queue<int,vector<int>,cmp>q;
	memset(dis,0x3f,sizeof(dis));
	dis[st]=0,vis[st]=1;
	q.push(st);
	while(!q.empty())
	{
		int u=q.top();
		q.pop();
		vis[u]=0;
		for(int i=0;i<e[u].size();i++)
		{
			int to=e[u][i].to;
			if(dis[to]>dis[u]+e[u][i].w)
			{
				fa[to]=u;
				dis[to]=dis[u]+e[u][i].w;
				if(vis[to]==0)
				{
					vis[to]=1;
					q.push(to);
				}
			}
		}
	}
}
void spfa2(int st)
{
	priority_queue<int,vector<int>,cmp>q;
	memset(dis2,0x3f,sizeof(dis2));
	dis2[st]=0,vis[st]=1;
	q.push(st);
	while(!q.empty())
	{
		int u=q.top();
		q.pop();
		vis[u]=0;
		for(int i=0;i<e[u].size();i++)
		{
			int to=e[u][i].to;
			if(dis2[to]>dis2[u]+e[u][i].w)
			{
				dis2[to]=dis2[u]+e[u][i].w;
				if(vis[to]==0)
				{
					vis[to]=1;
					q.push(to);
				}
			}
		}
	}
}

int dfn_cnt;
vector<int>ed[100001];
int dfn[100001];
int dep[100001];
int siz[100001];
int f[100001][21];
void dfs(int u,int fa)
{
	dfn[++dfn_cnt]=u;
	dep[u]=dep[fa]+1;
	siz[u]=1;
	f[u][0]=fa;
	for(int i=1;i<=20;i++)
		f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<ed[u].size();i++)
	{
		dfs(ed[u][i],u);
		siz[u]+=siz[ed[u][i]];
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--)
		if(dep[f[x][i]]>=dep[y])
			x=f[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
struct node
{
	int x,y;
	node(int x1=0,int y1=0){x=x1,y=y1;}
};
bool cmp(node a,node b){if(a.x!=b.x)return a.x<b.x;return a.y>b.y;}
int u[100001],v[100001],w[100001];
map<pair<int,int>,int>mp1,mp2;
signed main()
{
	
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	int n,m,q;
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
		e[u[i]].push_back(edge(v[i],w[i]));
		e[v[i]].push_back(edge(u[i],w[i]));
		if(u[i]>v[i]) swap(u[i],v[i]);
		if(!mp1[make_pair(u[i],v[i])]||w[i]<mp1[make_pair(u[i],v[i])])
		{
			swap(mp1[make_pair(u[i],v[i])],mp2[make_pair(u[i],v[i])]);
			mp1[make_pair(u[i],v[i])]=w[i];
		}
		else if(!mp2[make_pair(u[i],v[i])]||mp2[make_pair(u[i],v[i])]>w[i])
			mp2[make_pair(u[i],v[i])]=w[i];
	}
	spfa(1);
	spfa2(n);
	for(int i=1;i<=n;i++)
		ed[fa[i]].push_back(i);
	dfs(1,0);
	vector<node >tmp,v1;
	for(int i=0;i<e[n].size();i++)
		tmp.push_back(node(dis[e[n][i].to]+e[n][i].w,dep[lca(e[n][i].to,n)]));
	sort(tmp.begin(),tmp.end(),cmp);
	int pre=999999999;
	for(int i=0;i<tmp.size();i++)
	{
		if(tmp[i].y>=pre)continue;
		v1.push_back(tmp[i]);
		pre=tmp[i].y;
	}
	
	while(q--)
	{
		int cur,val;
		scanf("%lld%lld",&cur,&val);
		int x=u[cur],y=v[cur];
		if(mp2[make_pair(min(x,y),max(x,y))]) 
			val=min(val,mp2[make_pair(min(x,y),max(x,y))]);
		if(dep[x]<dep[y]) swap(x,y);
		if(val>=w[cur])
		{
			if(fa[x]==y)
			{
				if(dfn[n]>=dfn[x]&&dfn[n]<=dfn[x]+siz[x])
				{
					if(x==n)
					{
						if(v1.size()==1)
							printf("%lld\n",dis[n]+val-w[cur]);
						else
							printf("%lld\n",min(dis[n]+val-w[cur],v1[1].x));
					}
					else
					{
						int l=-1,r=v1.size();
						while(l+1<r)
						{
							int mid=(l+r)/2;
							if(v1[mid].y<=dep[y])
								r=mid;
							else
								l=mid;
						}
						if(r!=v1.size())
							printf("%lld\n",min(dis[n]+val-w[cur],v1[r].x));
						else
							printf("%lld\n",dis[n]+val-w[cur]);
					}
				}
				else printf("%lld\n",dis[n]);
			}
			else printf("%lld\n",dis[n]);
		}
		else
			printf("%lld\n",min(min(dis[x]+dis2[y]+val,dis[y]+dis2[x]+val),dis[n]));
	}
	return 0;
}
/*
4 5 1
1 2 2
2 4 3
1 4 7
1 3 1
3 4 5
1 4
*/