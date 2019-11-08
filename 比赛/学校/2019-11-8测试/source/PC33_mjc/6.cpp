#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxm=200010;
const int maxn=10010;
int n,m;

struct node{
	int to;
	int next;
	int w;
}e[maxm];
int head[maxn],cnt;
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	e[cnt].w=w;
	head[u]=cnt;
} 
void clear(){
	cnt=0;
	memset(head,0,sizeof(head));
}
struct pp{
	int ind;
	int v;
};
struct cmp{
	bool operator ()(const pp &a,const pp &b){
		return a.v>b.v;
	} 
};
priority_queue<pp,vector<pp>,cmp> pq;
int dis[maxn],vis[maxn];
void dj(){
	memset(vis,0,sizeof(vis));
	memset(dis,inf,sizeof(dis));
	dis[1]=0;
	pq.push((pp){1,0});
	while(!pq.empty()){
		int u=pq.top().ind;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w;
				pq.push((pp){v,dis[v]});
			}
		}
	}
}

int main(){
	freopen("6.in","r",stdin);
	freopen("6.out","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF){
		clear();
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
		}
		dj();
		printf("%d\n",dis[n]);
	}
}
