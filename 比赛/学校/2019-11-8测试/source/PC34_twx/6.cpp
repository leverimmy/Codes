#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 10010;
const int M = 100010;
int n,m;
int cnte,head[N];
struct edge{
	int to,nxt,w;
}e[M<<1];
void add(int u,int v,int w){
	e[++cnte]=(edge){v, head[u], w};
	head[u]=cnte;
}
struct sta{
	int dis,id;
};
bool operator < (sta x, sta y){
	return x.dis > y.dis;
}
int dis[N];
bool vis[N];
void dij(){
	priority_queue<sta> q;
	q.push((sta){0, 1});
	memset(vis, 0, sizeof vis);
	memset(dis, 0x3f, sizeof dis);
	dis[1]=0;
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
				q.push((sta){dis[v], v});
			}
		}
	}
}
int main(){
	freopen("6.in", "r", stdin);
	freopen("6.out", "w", stdout);
	while(scanf("%d%d",&n,&m)){
		cnte=0;
		memset(head, 0, sizeof head);
		for(int i=1; i<=m; i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u, v, w);
		}
		dij();
		printf("%d\n",dis[n]);
	}
	return 0;
}

