#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
#include<cctype>
#include<stack>
#include<queue>
using namespace std;
const int M=200200;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int n,m,ans,cnt=1,head[M];
struct edge{
	int nxt,to,val;
}e[M];
inline void add_edge(int u,int v,int w){
	e[++cnt].nxt=head[u],head[u]=cnt,e[cnt].to=v,e[cnt].val=w;
}
queue<int>q;
int dep[M],s,t;
inline int bfs(void){
	memset(dep,-1,sizeof(dep));
	dep[s]=0;
	q.push(s);
	while (!q.empty()){
		int h=q.front();q.pop();
		for (int i=head[h];i;i=e[i].nxt){
			if (dep[e[i].to]==-1&&e[i].val){
				dep[e[i].to]=dep[h]+1;q.push(e[i].to);	
			}
		}
	}
	return ~dep[t];
}
inline int dfs(int u,int limit){
	int flow=0;
	if (u==t||limit<=0) return limit; 
	for (int i=head[u];i;i=e[i].nxt){
		if (dep[e[i].to]==dep[u]+1&&e[i].val){
			int f=dfs(e[i].to,min(limit,e[i].val));
			if (f){
				limit-=f,flow+=f;
				e[i].val-=f,e[i^1].val+=f;
			}
			if (limit<=0) return flow;
		} 
	}
	if (!flow) dep[u]=1;
	return flow;
}
inline void dinic(){
	while (bfs())
		ans+=dfs(s,inf);
}
signed main(void){
	freopen("8.in","r",stdin);
	freopen("8.out","w",stdout);
	n=read(),m=read();
	s=0,t=2*n+1;
	for (int i=1;i<=m;i++){
		int u=read(),v=read();
		add_edge(u,v+n,1),add_edge(v+n,u,0);
	}
	for (int i=1;i<=n;i++)
		add_edge(s,i,1),add_edge(i,s,0),add_edge(i+n,t,1),add_edge(t,i+n,0);
	dinic();
	printf("%d",ans);
	return 0;
}
