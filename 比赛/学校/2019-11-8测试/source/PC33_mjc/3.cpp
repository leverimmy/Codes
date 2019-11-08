#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxm=200010;
const int maxn=10010;
int n,m;
struct node{
	int to;
	int next;
}e[maxm];
int head[maxn],cnt;
void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int ind,dfn[maxn],low[maxn]; 
int bk[maxm];
void clear(){
	cnt=1;
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(head,0,sizeof(head));
	memset(bk,0,sizeof(bk));
}

void tarjan(int u,int num){
	dfn[u]=low[u]=++ind;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(!dfn[v]){
			tarjan(v,i);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				bk[i]=bk[i^1]=1;
			}
		}
		else if(i!=(num^1)){
			low[u]=min(low[u],dfn[v]);
		}
	}
}
int main(){
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF){
		clear();
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u); 
		}
		for(int i=1;i<=n;i++){
			if(!dfn[i]){
				tarjan(i,1);
			}
		}
		int mjc=0;
		for(int i=2;i<=m*2+1;i++){
			if(bk[i]) mjc++;
		}
		printf("%d\n",mjc/2);
	}
}
