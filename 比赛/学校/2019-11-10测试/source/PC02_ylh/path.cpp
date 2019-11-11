#include <bits/stdc++.h>
#define maxn 100005
int depth[maxn],dep[maxn],anc[maxn][20]={0},n,u,v,w,vis[maxn],head[maxn]={0},tail=0,sum=0,ans=1e9,sel=0;

struct edge {
	int v,w,next;
}edges[maxn<<1];
void add_edge(int u,int v,int w){
	edges[++tail].v=v;
	edges[tail].w=w;
	edges[tail].next=head[u];
	head[u]=tail;
}

void dfs1(int u,int f){
	for(int i=head[u];i;i=edges[i].next){
		int v=edges[i].v;
		if (v==f)continue;
		depth[v]=depth[u]+edges[i].w;
		dfs1(v,u);
	}if (depth[u]>depth[sel])sel=u;
}

void dfs2(int u,int f){
	depth[u]=depth[f]+1;
	anc[u][0]=f;
	for(int i=1;i<=18;++i)anc[u][i]=anc[anc[u][i-1]][i-1];
	for(int i=head[u];i;i=edges[i].next){
		int v=edges[i].v;
		if (v==f)continue;
		dep[v]=dep[u]+edges[i].w;dfs2(v,u);
	}
}

int lca(int u,int v){
	if (depth[u]<depth[v])std::swap(u,v);
	for(int i=18;i>=0;i--)if (depth[anc[u][i]]>=depth[v])u=anc[u][i];
	if (u==v)return u;
	for(int i=18;i>=0;i--)if (anc[u][i]!=anc[v][i]){u=anc[u][i];v=anc[v][i];}
	return anc[u][0];
}

int dis(int u,int v){return dep[u]+dep[v]-2*dep[lca(u,v)];}

int main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
//	freopen("2.out1","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);add_edge(v,u,w);sum+=w*2;
	}int flag=0;
	for(int i=1;i<=n;++i){scanf("%d",&vis[i]);if (vis[i])flag=1;}
	if (!flag){printf("-1");return 0;}
	dfs1(1,0);u=sel;sel=0;std::memset(depth,0,sizeof(depth));dfs1(u,0);v=sel;std::memset(depth,0,sizeof(depth));
	dfs2(1,0);
	for(int i=1;i<=n;++i)if (vis[i])ans=std::min(ans,sum-std::max(dis(u,i),dis(v,i)));
	printf("%d",ans);
	return 0;
}
