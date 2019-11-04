#include<bits/stdc++.h>
using namespace std;
const int maxm=1000010; 
int depth[1000010],p[1000010][21];
struct node{
	int to;
	int next;
}e[maxm];
int head[maxm],cnt;
void add(int u,int v){
	e[++cnt].next=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
void dfs(int u,int fa){
	depth[u]=depth[fa]+1;
	p[u][0]=fa;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v!=fa){
			dfs(v,u);
		}
	}
}
int lca(int u,int v){
	if(depth[u]<depth[v]) swap(u,v);
	for(int i=20;i>=0;i--){
		if(depth[u]-(1<<i)>=depth[v]){
			u=p[u][i];
		}
	}
	if(u==v) return u;
	for(int i=20;i>=0;i--){
		if(p[u][i]!=p[v][i]){
			u=p[u][i];
			v=p[v][i];
		}
	}
	return p[u][0];
}
int n,m,s;
int main(){
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d",&x);
		if(x==0) s=i;
		else{
			add(x,i);
			add(i,x);
		}
	}
	dfs(s,0);
	for(int i=1;i<=20;i++){
		for(int x=1;x<=n;x++){
			p[x][i]=p[p[x][i-1]][i-1];
		}
	}
	int op=0;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int t=lca(x^op,y^op);
		printf("%d\n",t);
		op=t;
	}
}








