#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define int long long
using namespace std;
const int N = 5010;
const int M = 100010;
const int INF = 0x3f3f3f3f;
int n,m;
vector<int> pro[N]; 
int cnte,head[N];
struct edge{
	int to,nxt,w;
}e[M<<1];
void add(int u,int v,int w){
	e[++cnte]=(edge){v, head[u], w};
	head[u]=cnte; 
}
struct sta{
	int u,dis;
};
bool operator < (sta x,sta y){
	return x.dis>y.dis;
}
bool vis[N],spe[N];
int blk[N];
int t[N];
void bfs(){
	priority_queue<sta> q;
	q.push((sta){1, 0});
	while(!q.empty()){
		sta now=q.top();
		q.pop();
		int u=now.u;
		if(vis[u]){
			continue;
		}
		if(blk[u]){
			if(spe[u]){
				puts("Mission Failed");
				exit(0);
			}
			spe[u]=1;
			q.push((sta){now.u, INF});
			continue;
		}
		if(u==n){
			printf("%lld\n",now.dis);
			exit(0);
		}
		vis[u]=1;
		if(spe[u]){
			now.dis=t[u];
		}
		int siz=pro[u].size();
		for(int i=0; i<siz; i++){
			int v=pro[u][i];
			blk[v]--;
			t[v]=max(t[v], now.dis);
		}
		for(int i=head[u]; i; i=e[i].nxt){
			int v=e[i].to,w=e[i].w;
			if(!vis[v]){
				q.push((sta){v, now.dis+w});
			} 
		}
	}
}
signed main(){
	freopen("bomb.in", "r", stdin); 
	freopen("bomb.out", "w", stdout); 
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=m; i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u, v, w);
		add(v, u, w);
	}
	for(int i=2; i<=n-1; i++){
		int k;
		scanf("%lld",&k);
		for(int j=1; j<=k; j++){
			int v;
			scanf("%lld",&v);
			pro[i].push_back(v);
			blk[v]++;
			t[v]=0;
		}
	}
	bfs();
	puts("Mission Failed");
	return 0;
}

