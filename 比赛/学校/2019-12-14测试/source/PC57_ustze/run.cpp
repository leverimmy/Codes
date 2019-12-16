#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
int n,m,q;
struct E{
	int u,v,w;
}e[N];
struct edge{
	int to,w;
	edge(int x=0,int y=0){to=x,w=y;}
};
vector<edge> G[N];
inline bool cmp(const E &a,const E &b){
	return a.w<b.w;
}
int fa[N][20],d[N][20],dep[N];
struct Union_Set{
	int fa[N];
	inline void init(){for(int i=1;i<=n;i++) fa[i]=i;}
	inline int findf(int x){return fa[x]==x?x:fa[x]=findf(fa[x]);}
	inline bool merge(int x,int y){
		x=findf(x),y=findf(y);
		if(x==y) return 0;
		fa[x]=y;return 1;
	}
}S;
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	for(int i=1;i<20;i++) {
		fa[u][i]=fa[fa[u][i-1]][i-1];
		d[u][i]=max(d[u][i-1],d[fa[u][i-1]][i-1]);
	}
	for(int i=0;i<G[u].size();i++) {
		edge &e=G[u][i];
		if(e.to==f) continue;
		d[e.to][0]=e.w;fa[e.to][0]=u;
		dfs(e.to,u);
	}
}
inline int calc(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	int ans=0;
	for(int i=19;i>=0;i--) if(((dep[u]-dep[v])>>i)&1) ans=max(ans,d[u][i]),u=fa[u][i];
	if(u==v) return ans;
	for(int i=19;i>=0;i--) {
		if(fa[u][i]!=fa[v][i]) {
			ans=max(ans,max(d[u][i],d[v][i]));
			u=fa[u][i],v=fa[v][i];
		}
	}
	if(u!=v) ans=max(ans,max(d[u][0],d[v][0]));
	return ans;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	}
	sort(e+1,e+m+1,cmp);
	S.init();
	for(int i=1;i<=m;i++){
		if(S.merge(e[i].u,e[i].v)) {
			G[e[i].u].push_back(edge(e[i].v,e[i].w));
			G[e[i].v].push_back(edge(e[i].u,e[i].w));
		}
	}
	dfs(1,0);
	q=read();
	while(q--){
		int u=read(),v=read();
		printf("%d\n",calc(u,v));
	}
	return 0;
}
