#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 2010;
const int M = 10010;
int n,m,ans;
int cnte,head[N];
struct edge{
	int to,nxt;
}e[M];
void add(int u,int v){
	e[++cnte]=(edge){v, head[u]};
	head[u]=cnte;
}
int match[N];
bool vis[N];
bool dfs(int u){
	vis[u]=1;
	for(int i=head[u]; i; i=e[i].nxt){
		int v=e[i].to;
		if(vis[v]){
			continue;
		}
		if(!match[v] || dfs(v)){
			match[v]=u;
			return 1;
		}
	}
	return 0;
} 
int main(){
	freopen("8.in", "r", stdin);
	freopen("8.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u, v+n);
		add(v+n, u);
	}
	for(int i=1; i<=2*n; i++){
		if(!match[i]){
			memset(vis, 0, sizeof vis);
			ans+=dfs(i);
		}
	}
	printf("%d\n",ans);
	return 0;
}

