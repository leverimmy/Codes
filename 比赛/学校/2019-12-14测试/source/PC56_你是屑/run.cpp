#include <bits/stdc++.h>
#define maxn 300005
int u[maxn],v[maxn],w[maxn],fa[maxn]={0},depth[maxn],anc[maxn][19],max[maxn][19],n,m,tail=0,head[maxn],rank[maxn],q;
struct edge {
	int v,w,next;
}edges[maxn<<1];
void add_edge(int u,int v,int w){
	edges[++tail].v=v;
	edges[tail].w=w;
	edges[tail].next=head[u];
	head[u]=tail;
}

int cmp(int a,int b){return w[a]<w[b];}

int getf(int x){return fa[x]?fa[x]=getf(fa[x]):x;}
int merge(int u,int v){
	int f1=getf(u),f2=getf(v);
	if (f1==f2)return 0;
	fa[f1]=f2;return 1;
}

void dfs(int u,int f=0){
	anc[u][0]=f;depth[u]=depth[f]+1;
	for(int i=1;i<=18;++i){
		anc[u][i]=anc[anc[u][i-1]][i-1];
		max[u][i]=std::max(max[u][i-1],max[anc[u][i-1]][i-1]);
	}for(int i=head[u];i;i=edges[i].next){
		int v=edges[i].v;
		if (v==f)continue;
		max[v][0]=edges[i].w;
		dfs(v,u);
	}
}

int query(int u,int v){
	int ans=0;
	if (depth[u]<depth[v])std::swap(u,v);
	for(int i=18;i>=0;i--)if (depth[anc[u][i]]>=depth[v]){ans=std::max(ans,max[u][i]);u=anc[u][i];}
	if (u==v)return ans;
	for(int i=18;i>=0;i--)if (anc[u][i]!=anc[v][i]){
		ans=std::max(std::max(max[u][i],ans),max[v][i]);
		u=anc[u][i];v=anc[v][i];
	}return std::max(std::max(max[u][0],max[v][0]),ans);
}
		

int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)scanf("%d%d%d",&u[i],&v[i],&w[i]),rank[i]=i;
	std::sort(rank+1,rank+m+1,cmp);
	for(int i=1;i<=m;++i)
		if (merge(u[rank[i]],v[rank[i]])){add_edge(u[rank[i]],v[rank[i]],w[rank[i]]);add_edge(v[rank[i]],u[rank[i]],w[rank[i]]);}
	dfs(1);
	scanf("%d",&q);
	while (q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",query(x,y));
	}return 0;
}
