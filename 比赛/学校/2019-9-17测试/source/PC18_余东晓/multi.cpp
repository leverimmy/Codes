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
#define INF 127
struct edge{int to,next;double weight;}a[200020];int head[100010],cnt(0);void addedge(int x,int y,double w){a[cnt]=(edge){y,head[x],w};head[x]=cnt++;}
double dist[100010];int pre[100010];bool vis[100010];struct node{double d;int id;node(){}node(double d,int id):d(d),id(id){}};bool operator <(node x,node y){return x.d>y.d;}
void dijkstra(int s)
{
	memset(dist,INF,sizeof(dist));memset(vis,0,sizeof(vis));std::priority_queue<node>q;dist[s]=0;q.push(node(0,s));
	while(!q.empty()){node t=q.top();q.pop();int u=t.id;if(vis[u])continue;vis[u]=1;for(int i=head[u];i!=-1;i=a[i].next){int v=a[i].to;if(dist[v]>t.d+a[i].weight){dist[v]=t.d+a[i].weight;pre[v]=u;q.push(node(dist[v],v));}}}
}
signed main()
{
	freopen("multi.in","r",stdin);freopen("multi.out","w",stdout);memset(head,-1,sizeof(head));memset(pre,-1,sizeof(pre));int n,m;scanf("%d%d",&n,&m);
	while(m--){int x,y,w;scanf("%d%d%d",&x,&y,&w);double k=log10((double)w);addedge(x,y,k);addedge(y,x,k);}int s,t;scanf("%d%d",&s,&t);dijkstra(s);std::vector<int>ans;
	for(int u=t;u!=-1;u=pre[u])ans.push_back(u);reverse(ans.begin(),ans.end());for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);return puts(""),0;
}
