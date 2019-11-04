#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 300010;
const int M = 1500010;
const int INF = 0x3f3f3f3f;
int n,m,ans;
int o[N],r[N];
int cnte,head[N];
struct edge{
	int to,nxt,w;
}e[M<<1];
void add(int u,int v,int w){
	e[++cnte]=(edge){v, head[u], w};
	head[u]=cnte;
}
struct sta{
	int id,dis;
};
bool operator < (sta x,sta y){
	return x.dis > y.dis;
}
int dis[N];
bool vis[N];
void dijsktra(int s){
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[s]=0;
	priority_queue<sta> q;
	q.push((sta){s, 0});
	while(!q.empty()){
		sta now=q.top();
		q.pop();
		int u=now.id;
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=head[u]; i; i=e[i].nxt){
			int v=e[i].to,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push((sta){v, dis[v]});
			}
		}
	}
}
bool cmp(int x,int y){
	if(dis[x]==dis[y]){
		return r[x]<r[y];
	}
	return dis[x]<dis[y];
}
int main(){
	freopen("serves.in", "r", stdin);
	freopen("serves.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%d",&r[i]);
		o[i]=i;
	}
	for(int i=1; i<=m; i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u, v, w);
		add(v, u, w);
	}
	for(int i=1; i<=n; i++){
		dijsktra(i);
		sort(o+1, o+1+n, cmp);
		int cnt=0,lastdis=-1,lastr=-1;
		for(int j=1; j<=n; j++){
			int x=o[j];
			if(lastdis<dis[x]){
				lastdis=dis[x];
				ans+=cnt;
				cnt=0;
			}
			if(lastr<r[x]){
				lastr=r[x];
				cnt=1;
			}
			else if(lastr==r[x]){
				cnt++;
			}
		}
		ans+=cnt;
		continue;
	}
	printf("%d\n",ans);
	return 0;
}

