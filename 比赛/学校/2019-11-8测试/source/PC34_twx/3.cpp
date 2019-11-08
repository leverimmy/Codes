#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int N = 10010;
const int M = 100010;
int n,m,ans;
int cnte,head[N];
struct edge{
	int to,nxt;
	bool is;
}e[M<<1];
void add(int u,int v){
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	e[cnte].is=0;
	head[u]=cnte;
}
int dfn[N],low[N],idx;
void tarjan(int u,int E){
	dfn[u]=low[u]=++idx;
	for(int i=head[u]; i; i=e[i].nxt){
		int v=e[i].to;
		if(!dfn[v]){
			tarjan(v, i);
			low[u]=min(low[u], low[v]);
			if(dfn[u]<low[v]){
				e[i].is=1;
				e[i^1].is=1;
			}
		}
		else if(i!=(E^1)){
			low[u]=min(low[u], dfn[v]);
		}
	}
}
int main(){
	freopen("3.in", "r", stdin);
	freopen("3.out", "w", stdout);
	while(scanf("%d%d",&n,&m)){
		cnte=1;
		ans=0;
		idx=0;
		memset(head, 0, sizeof head);
		memset(dfn, 0, sizeof dfn);
		memset(low, 0, sizeof low);
		for(int i=1; i<=m; i++){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u, v);
			add(v, u);
		}
		for(int i=1; i<=n; i++){
			if(!dfn[i]){
				tarjan(i, 0);
			}
		}
		for(int i=0; i<=cnte; i++){
			ans+=e[i].is;
		}
		printf("%d\n",ans>>1);
	}
	return 0;
}

