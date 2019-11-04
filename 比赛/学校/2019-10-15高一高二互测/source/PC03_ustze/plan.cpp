#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
const int N=100005;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
struct edge{
	int to,w;
	edge(int x,int y){to=x,w=y;}
};
vector<edge> G[N];
int n,m;
int dis[N],pre[N];
int flag[N];
queue<int> q;
void dij(){
	memset(dis,0x3f,sizeof(dis));
	q.push(1);dis[1]=0;
	while(!q.empty()){
		int u=q.front();q.pop();flag[u]=0;
		for(int i=0;i<G[u].size();i++){
			edge e=G[u][i];
			if(dis[e.to]>dis[u]+e.w){
				dis[e.to]=dis[u]+e.w;pre[e.to]=e.w;
				if(!flag[e.to]) flag[e.to]=1,q.push(e.to);
			}else if(dis[e.to]==dis[u]+e.w&&pre[e.to]>e.w){
				pre[e.to]=e.w;
				if(!flag[e.to]) flag[e.to]=1,q.push(e.to);
			}
		}
	}
}
int main(){
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		G[u].push_back(edge(v,w));
		G[v].push_back(edge(u,w));
	} 
	dij();
	int res=0;
	for(int i=2;i<=n;i++) res+=pre[i];
	printf("%d",res);
	return 0;
}
