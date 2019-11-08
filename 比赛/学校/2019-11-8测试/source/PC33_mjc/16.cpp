#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxm=20010;
const int maxn=10010;
int n,m;
struct node{
	int to;
	int next;
	int w;
}e[maxm];
int head[maxn],cnt;
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	e[cnt].w=w;
	head[u]=cnt;
} 
int f;
int vis[maxn],dis[maxn],tp[maxn];
void spfa(){
	memset(vis,0,sizeof(vis));
	memset(dis,inf,sizeof(dis));
	queue<int >q ;
	dis[1]=0;
	vis[1]=1;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0; 
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w;
				if(!vis[v]){
					vis[v]=1;
					tp[v]++;
					if(tp[v]==n){
						f=1;
						break;
					}
					q.push(v);
				}
			}
		}
	}
}
void clear(){
	memset(tp,0,sizeof(tp));
	memset(head,0,sizeof(head));
	cnt=0;
	f=0;
}
int main(){
	freopen("16.in","r",stdin);
	freopen("16.out","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF){
		clear();
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
		}
		spfa();
		if(f){
			printf("yes\n"); 
		}
		else{
			printf("no\n");
		} 
	} 
}
