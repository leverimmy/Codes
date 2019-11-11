#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
struct edge{
	int to,w;
	edge(int a=0,int b=0){to=a,w=b;}
};
vector<edge> G[N];
int n;
int c[N],dep[N],mx_dep[N],kon[N];
vector<int> pre[N];
int res=0,ans=0;
void dfs(int u,int f){
	pre[u].resize(G[u].size()+1);
	for(int i=0;i<G[u].size();i++){
		edge e=G[u][i];int v=e.to;
		if(v==f) continue;
		dep[v]=dep[u]+e.w;
		dfs(v,u);
		mx_dep[u]=max(mx_dep[u],mx_dep[v]+e.w);
		pre[u][i+1]=max(pre[u][i],mx_dep[v]+e.w);
	}
}
void dfs(int u,int f,int w){
	if(c[u]) {
		ans=max(ans,max(mx_dep[u],w));
	}
	int suf=0;
	for(int i=G[u].size()-1;i>=0;i--){
		edge e=G[u][i];int v=e.to;
		if(v==f) continue;
		dfs(v,u,max(max(suf,pre[u][i]),w)+e.w);
		suf=max(suf,mx_dep[v]+e.w);
	}
}
int main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	n=read();
	for(int i=1;i<n;i++) {
		int x=read(),y=read(),w=read();
		res+=2*w;
		G[x].push_back({y,w});
		G[y].push_back({x,w});
	}
	for(int i=1;i<=n;i++) c[i]=read();
	dfs(1,0);
	dfs(1,0,0);
	if(ans!=0) printf("%d",res-ans);
	else printf("-1");
	return 0;
} 
