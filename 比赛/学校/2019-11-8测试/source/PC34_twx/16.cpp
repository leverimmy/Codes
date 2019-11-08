#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1010;
const int M = 2010;
int n,m;
int cnte,head[N];
struct edge{
	int to,nxt,w;
}e[M];
void add(int u,int v,int w){
	e[++cnte]=(edge){v, head[u], w};
	head[u]=cnte;
}
bool V[N];
int cnt[N],dis[N];
bool vis[N];
queue<int> q;
bool spfa(int s){
	memset(cnt, 0, sizeof cnt);
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[s]=0;
	vis[s]=1;
	V[s]=1;
	cnt[s]++;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u]; i; i=e[i].nxt){
			int v=e[i].to,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				cnt[v]++;
				if(cnt[v]>=n){
					return 1;
				}
				if(!vis[v]){
					vis[v]=1;
					V[v]=1;
					q.push(v);
				}
			}
		}
	}
	return 0;
}
int main(){
	freopen("16.in", "r", stdin);
	freopen("16.out", "w", stdout);
	while(scanf("%d%d",&n,&m)){
		cnte=0;
		memset(head, 0, sizeof head);
		memset(V, 0, sizeof V);
		for(int i=1; i<=m; i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u, v, w);
		}
		bool flag=0;
		for(int i=1; i<=n; i++){
			if(!V[i]){
				if(spfa(i)){
					flag=1;
					break;
				}
			}
		}
		if(flag){
			puts("yes");
		}
		else{
			puts("no");
		}
	}
	
	return 0;
}

