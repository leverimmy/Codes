#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
const int maxm=400010;
struct pp{
	int u,v,s,e;
}in[maxm];
int n,m,t;
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
int vis[maxn];
int col[maxn];
int dfs(int u){
	queue<int > q;
	q.push(u);
	col[u]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(vis[v] && col[v]==col[u]) return 0;
			if(!vis[v]){
				col[v]=col[u]^1;
				q.push(v);
			}
		}
	}
	return 1;
}

int main(){
	freopen("grape.in","r",stdin);
	freopen("grape.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&in[i].u,&in[i].v,&in[i].s,&in[i].e);
		in[i].s++;
	}
	for(int i=1;i<=t;i++){
		memset(head,0,sizeof(head));
		cnt=0;
		memset(col,-1,sizeof(col));
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=m;j++){
			if(in[j].s<=i && in[j].e>=i){
				add(in[j].u,in[j].v);
				add(in[j].v,in[j].u);
			}
		}
		if(dfs(1)==1) printf("Yes\n");
		else{
			printf("No\n");
		} 
	}	
} 
