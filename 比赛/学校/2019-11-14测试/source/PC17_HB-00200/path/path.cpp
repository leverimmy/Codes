#include<bits/stdc++.h>
#define int long long
#define inf 1e15
using namespace std;
const int maxm=400010;
const int maxn=200010;
struct node{
	int to;
	int next;
	int w;
}e[maxm];
int head[maxn],cnt;
void add(int u,int v,int w){
	e[++cnt].next=head[u];
	e[cnt].to=v;
	e[cnt].w=w;
	head[u]=cnt;
} 
int n,m,q;
struct pp{
	int ind;
	int dis;
};

struct cmp{
	bool operator()(pp a,pp b){
		return a.dis>b.dis;
	}
};

priority_queue<pp,vector<pp>,cmp> pq;
int vis[maxn],dis[maxn];

void dj(){
	for(int i=1;i<=n;i++)
		dis[i]=inf;
	memset(vis,0,sizeof(vis));
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

struct op{
	int u,v,w;
}in[maxm];
signed main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&in[i].u,&in[i].v,&in[i].w);
	}
	for(int i=1;i<=q;i++){
		int t,x;
		scanf("%lld%lld",&t,&x);
		memset(head,0,sizeof(head));
		cnt=0;
		for(int j=1;j<=m;j++){
			if(j==t){
				add(in[j].u,in[j].v,x);
				add(in[j].v,in[j].u,x);				
			}
			else{
				add(in[j].u,in[j].v,in[j].w);
				add(in[j].v,in[j].u,in[j].w);				
			}
		}
		dj();
		printf("%lld\n",dis[n]);
	}	
}
