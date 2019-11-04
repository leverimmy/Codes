#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<stack>
#include<vector>
#include<queue>
#include<set>
using namespace std;
const int inf=0x3f3f3f3f;
const int M=800010;
const int N=200100;
inline int read(void){
	int f=1,x=0;char s=getchar();
	while (!isdigit(s)){if (s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48),s=getchar();}
	return x*f;
}
int cnt=1,head[M];
struct edge{
	int to,next,val;
}e[M];
inline void add_edge(int u,int v,int w){
	e[++cnt].to=v,e[cnt].next=head[u],head[u]=cnt,e[cnt].val=w;
}
int n,m,indgr[N],s,t,pre[N],dep[N],ans,b[N],c[N];
queue<int>q;
inline bool bfs(){
	memset(dep,-1,sizeof(dep));
	q.push(s);
	dep[s]=0;
	while (!q.empty()){
		int h=q.front();q.pop();
		for (int i=head[h];i;i=e[i].next){
			if (dep[e[i].to]==-1&&e[i].val>0){
				dep[e[i].to]=dep[h]+1;
				q.push(e[i].to);
			}
		}
	}
	return ~dep[t];
}
inline int dfs(int u,int limit){
	if (u==t||limit==0) return limit; 
	int flow=0;
	for (int i=head[u];i;i=e[i].next){
		if (dep[e[i].to]==dep[u]+1){
			int f=dfs(e[i].to,min(limit,e[i].val));
			if (f){
				pre[u]=e[i].to;
				e[i].val-=f,e[i^1].val+=f;
				flow+=f,limit-=f;
			}
			if (limit<=0) break;
		}
	}
	if (!flow) dep[u]=-1;
	return flow;
}
inline void dinic(){
	while (bfs()){
		ans+=dfs(s,inf);
	}
}
signed main(void){
	freopen("fantasy.in","r",stdin);
	freopen("fantasy.out","w",stdout);
	n=read(),m=read();
	s=0,t=n+m+1;
	for (int i=1;i<=m;i++){
		add_edge(s,i,1);
		add_edge(i,s,0);
		int a=read();b[i]=read(),c[i]=read();
		add_edge(i,b[i]+m,1);
		add_edge(b[i]+m,i,0);
		add_edge(i,c[i]+m,1);
		add_edge(c[i]+m,i,0);
		indgr[a]++;
	}
	for (int i=1;i<=n;i++){
		add_edge(i+m,t,indgr[i]);
		add_edge(t,i+m,0);
	}
	dinic();
	for (int i=1;i<=m;i++)
		printf("%d",pre[i]!=(b[i]+m));
	return 0;
}
