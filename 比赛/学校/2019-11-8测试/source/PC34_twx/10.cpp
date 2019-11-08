#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int N = 100010;
const int M = 1000010;
int n,m;
int cnte,head[N];
struct edge{
	int to,nxt;
}e[M];
void add(int u,int v){
	e[++cnte]=(edge){v, head[u]};
	head[u]=cnte;
}
int dfn[N],low[N],bel[N],col,idx;
stack<int> s;
void tarjan(int u){
	dfn[u]=low[u]=++idx;
	s.push(u);
	for(int i=head[u]; i; i=e[i].nxt){
		int v=e[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u], low[v]);
		}
		else if(!bel[v]){
			low[u]=min(low[u], dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		bel[u]=++col;
		while(s.top()!=u){
			bel[s.top()]=col;
			s.pop();
		}
		s.pop();
	}
}
int main(){
	freopen("10.in", "r", stdin);
	freopen("10.out", "w", stdout);
	while(scanf("%d%d",&n,&m)){
		cnte=col=idx=0;
		memset(head, 0, sizeof head);
		memset(dfn, 0, sizeof dfn);
		memset(low, 0, sizeof low);
		memset(bel, 0, sizeof bel);
		for(int i=1; i<=m; i++){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u, v);
		}
		for(int i=1; i<=n; i++){
			if(!dfn[i]){
				tarjan(i);
			}
		}
		printf("%d\n",col);
	}
	return 0;
}

