#include <bits/stdc++.h>
#define maxn 200005

struct edge {
	int v,next;double w;
}edges[maxn<<1];
int n,m,s,t,u,v,w,head[maxn]={0},tail=0,pre[maxn],dis[maxn],vis[maxn];double wl;
void add_edge(int u,int v,double w){
	edges[++tail].v=v;
	edges[tail].w=w;
	edges[tail].next=head[u];
	head[u]=tail;
}

void print(int x){
	if (!x)return;
	print(pre[x]);
	printf("%d ",x);
}

void this_is_not_dijkstra_and_i_dont_believe_it_will_get_TLE(){
	std::queue<int>q;q.push(s);vis[s]=1;
	for (int i=1;i<=n;++i)dis[i]=(1<<28);dis[s]=0;
	std::memset(pre,0,sizeof(pre));
	while (!q.empty()){
		int u=q.front();q.pop();
		for (int i=head[u];i;i=edges[i].next){
			int v=edges[i].v;
			if (dis[u]+edges[i].w<dis[v]){
				dis[v]=dis[u]+edges[i].w;pre[v]=u;
				if (!vis[v])q.push(v);vis[v]=1;
			}
		}vis[u]=0;
	}
}
			

int main(){
	freopen("multi.in","r",stdin);
	freopen("multi.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);double wl=std::log(w);
		add_edge(u,v,wl);add_edge(v,u,wl);
	}scanf("%d%d",&s,&t);
	this_is_not_dijkstra_and_i_dont_believe_it_will_get_TLE();
	print(t);
	return 0;
}
