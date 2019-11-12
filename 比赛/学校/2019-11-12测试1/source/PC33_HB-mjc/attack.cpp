#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
const int maxm=2000010;
struct node{
	int to;
	int next;
}e[maxm];
int head[maxn],cnt;
void add(int u,int v){
	e[++cnt].next=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
int pos,ans;
int val[maxn];
int d[maxn];
int vis[maxn],path[maxn];
int maxx;
void dfs1(int u,int fa){
	d[u]=d[fa]+val[u];
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v!=fa){
			dfs1(v,u);
		}
	}
}
void dfs2(int u,int fa){
	d[u]=d[fa]+val[u];
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v!=fa){
			dfs2(v,u);
		}
	}
}
int n;
int main(){
	freopen("attack.in","r",stdin);
	freopen("attack.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&val[i]);
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs1(1,0);
	for(int i=1;i<=n;i++){
		if(d[i]>maxx){
			maxx=d[i];
			pos=i;
		}
	}
	memset(d,0,sizeof(d));
	dfs2(pos,0);
}

