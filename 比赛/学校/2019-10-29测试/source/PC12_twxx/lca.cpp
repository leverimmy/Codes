#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100010;
int n,m;
int head[N],cnte;
struct edge{
	int to,nxt;
}e[N];
void add(int u,int v){
	e[++cnte]=(edge){v, head[u]};
	head[u]=cnte;
}
int dep[N],f[N][30];
void dfs(int u,int fa){
	f[u][0]=fa;
	for(int i=1; i<=20; i++){
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(int i=head[u]; i; i=e[i].nxt){
		int v=e[i].to;
		if(v!=fa){
			dep[v]=dep[u]+1;
			dfs(v, u);
		}
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]){
		swap(x, y);
	}
	for(int i=20; i>=0; i--){
		if(dep[f[x][i]]>=dep[y]){
			x=f[x][i];
		}
	}
	if(x==y){
		return x;
	}
	for(int i=20; i>=0; i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int main(){
	freopen("lca.in", "r", stdin);
	freopen("lca.out", "w", stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int fa;
		scanf("%d",&fa);
		add(fa, i);
	}
	dfs(0, 0);
	scanf("%d",&m);
	int lastans=0;
	for(int i=1; i<=m; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		x^=lastans;
		y^=lastans;
		lastans=lca(x, y);
		printf("%d\n",lastans);
	}
	return 0;
}

