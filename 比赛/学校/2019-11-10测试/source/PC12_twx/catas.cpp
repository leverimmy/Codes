#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 66000;
int n;
int d[N],cnte,head[N];
struct edge{
	int to,nxt;
}e[N];
void add(int u,int v){
	e[++cnte]=(edge){v, head[u]};
	head[u]=cnte;
}
int td[N];
bool vis[N];
int bfs(int s){
	int res=0;
	queue<int> q;
	q.push(s);
	memset(vis, 0, sizeof vis);
	memcpy(td, d, sizeof d);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		res++;
		for(int i=head[u]; i; i=e[i].nxt){
			int v=e[i].to;
			if(vis[v]){
				continue;
			}
			td[v]--;
			if(!td[v]){
				q.push(v);
			}
		}
	}
	return res-1;
}
int main(){
	freopen("catas.in", "r", stdin);
	freopen("catas.out", "w", stdout);
	scanf("%d",&n);
	for(int u=1; u<=n; u++){
		int v;
		scanf("%d",&v);
		while(v){
			add(v, u);
			d[u]++;
			scanf("%d",&v);
		}
	}
	for(int i=1; i<=n; i++){
		printf("%d\n",bfs(i));
	}
	return 0;
}

