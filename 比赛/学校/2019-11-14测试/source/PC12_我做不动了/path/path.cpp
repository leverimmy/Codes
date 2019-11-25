#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200010;
int n,m,q;
int cnte,head[N];
bool mark[N<<1];
struct edge{
	int from,to,nxt,w;
}e[N<<1];
void add(int u,int v,int w){
	e[++cnte]=(edge){u, v, head[u], w};
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
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	priority_queue<sta> q;
	q.push((sta){0, 1});
	dis[1]=0;
	while(!q.empty()){
		sta now=q.top();
		q.pop();
		int u=now.id;
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=head[u]; i!=-1; i=e[i].nxt){
			int v=e[i].to,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push((sta){dis[v], v});
			}
		}
	}
}
signed main(){
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout); 
	scanf("%lld%lld%lld",&n,&m,&q);
	memset(head, -1, sizeof head);
	cnte=-1;
	for(int i=1; i<=m; i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u, v, w);
		add(v, u, w);
	}
	dij();
	int last=dis[n];
	for(int i=0; i<=cnte; i++){
		if(abs(dis[e[i].from]-dis[e[i].to])==e[i].w){
			mark[i]=1;
		}
		else{
			mark[i]=0;
		}
	}
	for(int i=1; i<=q; i++){
		int p,x;
		scanf("%lld%lld",&p,&x);
		int id=(p-1)<<1;
		int tmp=e[id].w;
		e[id].w=e[id^1].w=x;
		dij();
		e[id].w=e[id^1].w=tmp;
		printf("%lld\n",dis[n]);

//		if(x>e[id].w){
//			if(!mark[id]){
//				printf("%lld\n",last);
//			}
//			else{
//				int tmp=e[id].w;
//				e[id].w=e[id^1].w=x;
//				dij();
//				e[id].w=e[id^1].w=tmp;
//				printf("%lld\n",dis[n]);
//			}
//		}
//		else if(x==e[id].w){
//			printf("%lld\n",last);
//		}
//		else{
//			if(!mark[id]){
//				int tmp=e[id].w;
//				e[id].w=e[id^1].w=x;
//				dij();
//				e[id].w=e[id^1].w=tmp;
//				printf("%lld\n",dis[n]);
//			}
//			else{
//				printf("%lld\n",last-e[id].w+x);
//			}
//		}
	}
	return 0;
}

