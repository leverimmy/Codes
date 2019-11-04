#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int to;double w;
	edge(int x1=0,double x2=0){to=x1,w=x2;}
};
stack<int>st;
vector<edge>e[100001];
double dis[100001];
struct cmp
{
	bool operator()(int a,int b)
	{
		return dis[a]>dis[b];
	}
};
priority_queue<int,vector<int>,cmp>q;
int pre[100001];
int vis[100001];
void spfa(int s,int t)
{
	dis[s]=0;
	q.push(s);
	vis[s]=1;
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
				pre[to]=u;
				dis[to]=dis[u]+e[u][i].w;
				if(!vis[to])
				{
					q.push(to);
					vis[to]=1;
				}
			}
		}
	}
}
int main()
{
	freopen("multi.in","r",stdin);
	freopen("multi.out","w",stdout);
	int n,m,s,t;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,k;
		scanf("%d%d%d",&u,&v,&k);
		e[u].push_back(edge(v,log2(k)));
		e[v].push_back(edge(u,log2(k)));
	}
	scanf("%d%d",&s,&t);
	for(int i=1;i<=n;i++)
		dis[i]=999999999;
	spfa(s,t);
	while(t!=s)
	{
		st.push(t);
		t=pre[t];
	};
	st.push(s);
	while(!st.empty())
	{
		printf("%d ",st.top());
		st.pop();
	}
	return 0;
}
/*
4 4
1 2 3
2 4 2
4 3 2
1 3 15
1 3
*/