#include<bits/stdc++.h>
using namespace std;
int n;
int k[1000010];
int head[1000010],cnt;
struct node{
	int to;
	int next;
	int w;
}e[2000010];
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt; 
}	
int d[1000010];
int vis[1000010];
int ans=0;
int dfs(int u,int fa){
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v!=fa){
			d[v]=d[u]+e[i].w;
			dfs(v,u);
		}
	}
}
int tot;
int main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		tot+=w*2;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);		
	}
	for(int i=1;i<=n;i++){
		if(k[i]){
			memset(d,0,sizeof(d));
			dfs(i,0);
			for(int j=1;j<=n;j++){
				ans=max(ans,d[j]);
			}
		}
	}
	printf("%d\n",tot-ans);
}
 
