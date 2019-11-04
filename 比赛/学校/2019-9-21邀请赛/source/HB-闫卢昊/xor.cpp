#include <bits/stdc++.h>
#define maxn 100005
int n,m,head[maxn]={0},tail=0,vis[maxn],flag,x,y,k;

struct edge {
	int v,w,next;
}edges[500005<<1];
void add_edge(int u,int v,int w){
	edges[++tail].v=v;
	edges[tail].w=w;
	edges[tail].next=head[u];
	head[u]=tail;
}

void dfs(int u,int f){
	for (int i=head[u];i;i=edges[i].next){
		int v=edges[i].v;
		if (v==f)continue;
		if (vis[v]==-1){
			vis[v]=vis[u]^edges[i].w;
			dfs(v,u);
		} else {
			if (vis[v]!=(vis[u]^edges[i].w))flag=1;
		}
	}
}

void solve(){
	scanf("%d%d",&n,&m);
	tail=0;
	std::memset(head,0,sizeof(head));flag=0;
	std::memset(vis,-1,sizeof(vis));
	for (int i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&k);
		add_edge(x,y+1,k);add_edge(y+1,x,k);
	}for (int i=1;i<=n+1;++i){
		if (vis[i]==-1){vis[i]=0;dfs(i,0);}
	}
	if (flag)printf("No\n");
	else printf("Yes\n");
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int t;scanf("%d",&t);
	while (t--)solve();
	return 0;
}
