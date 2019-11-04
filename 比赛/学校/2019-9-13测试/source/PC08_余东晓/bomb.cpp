#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<cassert>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<vector>
#include<queue>
#define ll long long
#define INF 0x3f3f3f3f
struct edge{int to,next;ll weight;}a[200020];int head[5050],cnt(0);void addedge(int x,int y,ll w){a[cnt]=(edge){y,head[x],w};head[x]=cnt++;}
struct node{ll d;int id;node(){}node(ll d,int id):d(d),id(id){}};bool operator <(node x,node y){return x.d>y.d;}std::vector<int>to[5050];int vis[5050],ind[5050];ll vst[5050],dist[5050];
void dijkstra(int s,int n)
{
	memset(dist,INF,sizeof(dist));memset(vis,0,sizeof(vis));std::priority_queue<node>q;q.push(node(0,s));dist[s]=0;
	while(!q.empty())
	{
		node t=q.top();q.pop();int u=t.id;if(vis[u])continue;vis[u]=1;
		for(int i=0;i<to[u].size();i++){int v=to[u][i];ind[v]--;vst[v]=std::max(vst[v],dist[u]);if(!ind[v]){dist[v]=std::max(vst[v],dist[v]);q.push(node(dist[v],v));}}
		for(int i=head[u];i!=-1;i=a[i].next){int v=a[i].to;if(dist[v]>t.d+a[i].weight){dist[v]=t.d+a[i].weight;if(!ind[v])q.push(node(dist[v],v));}}
	}
}
signed main()
{
	freopen("bomb.in","r",stdin);freopen("bomb.out","w",stdout);memset(head,-1,sizeof(head));int n,m;scanf("%d%d",&n,&m);while(m--){int x,y;ll w;scanf("%d%d%lld",&x,&y,&w);addedge(x,y,w);addedge(y,x,w);}
	for(int i=2;i<=n-1;i++){int k;scanf("%d",&k);while(k--){int x;scanf("%d",&x);to[i].push_back(x);ind[x]++;}}dijkstra(1,n);if(dist[n]>=INF)return puts("Mission Failed"),0;return printf("%lld\n",dist[n]),0;
}
