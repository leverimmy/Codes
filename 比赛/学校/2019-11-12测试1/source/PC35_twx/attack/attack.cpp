#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
int read(){
	char ch=getchar();
	int res=0;
	while(ch<'0' || ch>'9'){
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}
int n,ans;
int a[N];
int cnte,head[N];
struct edge{
	int to,nxt,w;
}e[N<<1];
void add(int u,int v,int w){
	e[++cnte]=(edge){v, head[u], w};
	head[u]=cnte;
}
int dis[N];
int mark,maxdis,node1,node2;
void dfs1(int u,int fa){
	if(maxdis<dis[u]){
		maxdis=dis[u];
		mark=u;
	}
	for(int i=head[u]; i; i=e[i].nxt){
		int v=e[i].to,w=e[i].w;
		if(v!=fa){
			dis[v]=dis[u]+w-a[u]+a[v];
			dfs1(v, u);
		}
	}
}
int f[N];
void dfs2(int u,int fa){
	for(int i=head[u]; i; i=e[i].nxt){
		int v=e[i].to;
		if(v!=fa){
			f[v]=u;
			dfs2(v, u);
		}
	}
}
struct sta{
	int id,t;
};
bool blk[N];
//void paint(int u,int fa){
//	for(int i=head[u]; i; i=e[i].nxt){
//		int v=e[i].to;
//		if(v!=fa && !blk[v]){
//			bel[v]=col;
//			fir[col]=v;
//			paint(v, u);
//		}
//	}
//}
namespace work{
	bool vis[N];
	int dis[N];
	int mark,maxdis,node1,node2,C;
	void dfs1(int u,int fa){
		vis[u]=1;
		if(maxdis<dis[u]){
			maxdis=dis[u];
			mark=u;
		}
		for(int i=head[u]; i; i=e[i].nxt){
			int v=e[i].to,w=e[i].w;
			if(v!=fa && !blk[v]){
				dis[v]=dis[u]+w-a[u]+a[v];
				dfs1(v, u);
			}
		}
	}
	int cal(int s){
		memset(dis, 0, sizeof dis);
		dis[s]=a[s]<<1;
		maxdis=mark=0;
		dfs1(s, 0);
		
		memset(dis, 0, sizeof dis);
		dis[mark]=a[mark]<<1;
		maxdis=0;
		dfs1(mark, 0);
		return maxdis>>1;
	}
}
int main(){
	freopen("attack.in", "r", stdin);
	freopen("attack.out", "w", stdout);
	n=read();
	for(int i=1; i<=n; i++){
		a[i]=read();
	}
	for(int i=1; i<n; i++){
		int u=read(),v=read();
		add(u, v, a[u]+a[v]);
		add(v, u, a[u]+a[v]);
	}
	memset(dis, 0, sizeof dis);
	dis[1]=a[1]<<1;
	maxdis=mark=0;
	dfs1(1, 0);
	node1=mark;
	
	memset(dis, 0, sizeof dis);
	dis[mark]=a[mark]<<1;
	maxdis=mark=0;
	dfs1(node1, 0);
	node2=mark;
	
	ans=maxdis>>1;
	
	f[node1]=node1;
	dfs2(node1, 0);
	int now=node2;
	while(now!=node1){
		blk[now]=1;
		now=f[now];
	}
	blk[node1]=1;
	int tmp=0;
	for(int i=1; i<=n; i++){
		if(!blk[i] && !work::vis[i]){
			tmp=max(tmp, work::cal(i));
		}
	}
	printf("%d\n",ans+tmp);
	return 0;
}

