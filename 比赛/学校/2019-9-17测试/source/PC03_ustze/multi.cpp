#include<bits/stdc++.h>
using namespace std;
#define double long double
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s; 
}
const int N=1e5+5;
struct edge{
	int to;double w;
	edge(int x,double y){to=x,w=y;}
};
struct node{
	int u;double d;
	node(int x,double y){u=x,d=y;}
	bool operator < (const node &b) const {
		return d>b.d;
	}
};
int n,m,s,t;
vector<edge> G[N];
double dis[N];int vis[N];
priority_queue<node> q;
int pre[N];
void print(int x){
	if(x==s) {
		printf("%d ",s);
		return;
	}
	print(pre[x]);
	printf("%d ",x);
}
int main(){
	freopen("multi.in","r",stdin);
	freopen("multi.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		double W=log2(w);
		G[u].push_back(edge(v,W));
		G[v].push_back(edge(u,W));
	}
	s=read(),t=read();
	for(int i=1;i<=n;i++) dis[i]=1e15;
	dis[s]=0; 
	q.push(node(s,0));
	while(!q.empty()){
		int u=q.top().u;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<G[u].size();i++){
			edge e=G[u][i];
			if(dis[e.to]>dis[u]+e.w){
				dis[e.to]=dis[u]+e.w;
				pre[e.to]=u;
				q.push(node(e.to,dis[e.to]));
			}
		}
	}
	print(t);
	return 0;
}
