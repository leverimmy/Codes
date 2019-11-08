#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 10010;
const int M = 100010;
int n,m,ans;
int cnte;
struct edge{
	int u,v,w;
}e[M<<1];
bool operator < (edge x, edge y){
	return x.w < y.w;
}
void add(int u,int v,int w){
	e[++cnte]=(edge){u, v, w};
}
int fa[N];
int find(int x){
	return fa[x]==x ? x : fa[x]=find(fa[x]);
}
void kruscal(){
	sort(e+1, e+1+cnte);
	for(int i=1; i<=n; i++){
		fa[i]=i;
	}
	for(int i=1; i<=cnte; i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			fa[fv]=fu;
			ans+=w;
		}
	}
}
int main(){
	freopen("5.in", "r", stdin);
	freopen("5.out", "w", stdout);
	while(scanf("%d%d",&n,&m)){
		cnte=0;
		ans=0;
		for(int i=1; i<=m; i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u, v, w);
			add(v, u, w);
		}
		kruscal();
		printf("%d\n",ans);
	}
	return 0;
}

