#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int to,v;
	edge(int x1=0,int x2=0){to=x1,v=x2;}
};
vector<edge> e[1001];

int vis[1001],dis[1001];
struct cmp
{
	bool operator()(int a,int b)
	{
		return dis[a]>dis[b];
	}
};
void spfa(int st)
{
	priority_queue<int,vector<int>,cmp> q;
	memset(dis,0x3f,sizeof(dis));
	dis[st]=0;
	vis[st]=1;
	q.push(st);
	while(!q.empty())
	{
		int u=q.top();
		q.pop();
		vis[u]=0;
		for(int i=0;i<e[u].size();i++)
		{
			int to=e[u][i].to;
			if(dis[to]>dis[u]+e[u][i].v)
			{
				dis[to]=dis[u]+e[u][i].v;
				if(!vis[to])
				{
					q.push(to);
					vis[to]=1;
				}
			}
		}
	}
}
int r[1001];
bool cmp2(pair<int,int>a,pair<int,int>b){if(a.first!=b.first)return a.first<b.first;return a.second>b.second;}
int main()
{
		freopen("serves.in","r",stdin);
	freopen("serves.out","w",stdout);

    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
		scanf("%d",&r[i]);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
		e[u].push_back(edge(v,w));
		e[v].push_back(edge(u,w));
    }
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		spfa(i);
		vector<pair<int,int> >v;
		for(int j=1;j<=n;j++)
			v.push_back(make_pair(dis[j],r[j]));
		sort(v.begin(),v.end(),cmp2);
		int mx=0;
		for(int j=0;j<v.size();j++)
		{
			if(v[j].second>=mx)
				ans++,mx=max(mx,v[j].second);
		}
	}	
	printf("%d",ans);
    return 0;
}
