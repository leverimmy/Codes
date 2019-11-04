#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
const int N = 100010;
const double INF = 2147483647.0;
int n,m,s,t;
int cnte,head[N];
struct edge{
	int to,nxt;
	double w;
}e[N<<1];
void add(int u,int v,double w){
	e[++cnte]=(edge){v, head[u], w};
	head[u]=cnte;
}
double dis[N];
bool vis[N];
int pre[N];
void spfa(){
	for(int i=1; i<=n; i++){
		dis[i]=INF;
	}
	dis[s]=0;
	vis[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u]; i; i=e[i].nxt){
			int v=e[i].to;
			double w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pre[v]=u;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int ans[N],cnt;
int main(){
	freopen("multi.in", "r", stdin);
	freopen("multi.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		double W=log2(w);
		add(u, v, W);
		add(v, u, W);
	}
	scanf("%d%d",&s,&t);
	spfa();
	int now=t;
	while(now!=s){
		ans[++cnt]=now;
		now=pre[now];
	}
	ans[++cnt]=s;
	for(int i=cnt; i>=1; i--){
		printf("%d ",ans[i]);
	}
	return 0;
}

