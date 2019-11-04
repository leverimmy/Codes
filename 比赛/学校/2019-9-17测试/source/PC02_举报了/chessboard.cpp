#include <bits/stdc++.h>
#define maxn 2005
#define inf 998244353
char ch[maxn];
struct edge {
	int v,next,c;
}edges[maxn<<1];
int n,s,t,head[maxn]={0},tail=0,dis[maxn];
void add_edge(int u,int v,int c){
	edges[++tail].v=v;
	edges[tail].c=c;
	edges[tail].next=head[u];
	head[u]=tail;
}

int bfs(){
	std::queue<int>q;q.push(s);
	std::memset(dis,-1,sizeof(dis));dis[s]=0;
	while (!q.empty()){
		int u=q.front();q.pop();
		for (int i=head[u];i;i=edges[i].next){
			int v=edges[i].v;
			if (edges[i].c==0)continue;
			if (dis[v]!=-1)continue;
			dis[v]=dis[u]+1;q.push(v);
		}
	}return dis[t]!=-1;
}

int dfs(int u,int lim){
	if (u==t)return lim;
	for (int i=head[u];i;i=edges[i].next){
		if (edges[i].c==0)continue;
		int v=edges[i].v;
		if (dis[v]!=dis[u]+1)continue;
		int d=dfs(v,std::min(edges[i].c,lim));
		if (d){
			edges[i].c-=d;edges[((i-1)^1)+1].c+=d;
			return d;
		}
	}return 0;
}

int Dinic(){
	int totflow=0;
	while (bfs()){
		totflow+=dfs(s,inf);
	}return totflow;
}

int main(){
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	scanf("%d",&n);
	s=1000,t=1001;
	for (int i=1;i<=n;++i){
		add_edge(s,i*2,1);add_edge(i*2,s,0);add_edge(i*2+1,t,1);add_edge(t,i*2+1,0);
		scanf("%s",ch+1);
		for (int j=1;j<=n;++j){
			if (ch[j]=='.'){
				add_edge(i*2,j*2+1,1);add_edge(i*2+1,j*2,0);
			}
		}
	}printf("%d",Dinic());
	return 0;
}



