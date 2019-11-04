#include <bits/stdc++.h>
#define maxn 100005
#define maxm 500005
int n,m,u[maxm],v[maxm],w[maxm],rank[maxm],dis[maxn],head[maxn]={0},tail=0,fa[maxn]={0};
int cmp(int a,int b){return w[a]<w[b];}
int getf(int x){return fa[x]?fa[x]=getf(fa[x]):x;}
struct edge {
	int v,w,next;
}edges[500005<<1];
void add_edge(int u,int v,int w){
	edges[++tail].v=v;
	edges[tail].w=w;
	edges[tail].next=head[u];
	head[u]=tail;
}

void dfs(int u,int f,int max=0){
	dis[u]=max;
	for (int i=head[u];i;i=edges[i].next){
		int v=edges[i].v;
		if (v==f)continue;
		dfs(v,u,std::max(max,edges[i].w));
	}
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);rank[i]=i;
	}
	std::sort(rank+1,rank+m+1,cmp);
	for (int j=1;j<=m;++j){
		int i=rank[j];
		int f1=getf(u[i]),f2=getf(v[i]);
		if (f1==f2)continue;
		fa[f2]=f1;
		add_edge(u[i],v[i],w[i]);add_edge(v[i],u[i],w[i]);
	}dfs(1,0,0);int ans=0;
	for (int i=2;i<=n;++i)ans+=dis[i];
	printf("%d",ans);
	return 0;
}




