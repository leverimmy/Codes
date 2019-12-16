#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cctype>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define int long long
using namespace std;
const int M=1001*1001;
const int inf=9999999999999999LL;
const double eps=1e-6;
queue <int> q;
int cnt=1,head[3000],s,t,m,n;
struct edge{
	int to,from,next,flow,cost;
}e[M<<1];
inline int read(void){
	int f=1;int x=0;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<3)+(x<<1)+(s^48),s=getchar();}
	return x*f;
}
inline void add_edge(int u,int v,int w,int cost)
{
	e[++cnt].next=head[u],e[cnt].to=v,e[cnt].from=u;
	e[cnt].flow=w,e[cnt].cost=cost,head[u]=cnt;
}
int ans,pre[3000],vis[3000],dis[3000],flow[3000],last[3000],mflow,mcost;
inline bool SPFA(void)
{
	memset(pre,-1,sizeof(pre)),memset(vis,0,sizeof(vis));
	memset(dis,0x7f,sizeof(dis)),memset(flow,0x7f,sizeof(flow));
	dis[s]=0,vis[s]=1,q.push(s);
	while (!q.empty()){
		int h=q.front();q.pop();
		vis[h]=0;
		for (int i=head[h];i;i=e[i].next){
			if (dis[e[i].to]>dis[h]+e[i].cost&&e[i].flow>0){
				dis[e[i].to]=dis[h]+e[i].cost,pre[e[i].to]=h;
				last[e[i].to]=i,flow[e[i].to]=min(flow[h],e[i].flow);
				if (!vis[e[i].to]){
					vis[e[i].to]=1;
					q.push(e[i].to);
				}
			}
		}
	}
	return pre[t]!=-1;
}
inline void MCMF(void){
	while (SPFA()){
		int now=t;
		mflow+=flow[t];
		mcost+=flow[t]*dis[t];
		while (now!=s){
			e[last[now]].flow-=flow[t];
			e[last[now]^1].flow+=flow[t];
			now=pre[now];
		}
	}
}
int x[M],y[M],c[M];
signed main(void){
	freopen("offsheet.in","r",stdin);
	freopen("offsheet.out","w",stdout);
	n=read();
	s=0,t=2*n+1;
	for (int i=1;i<=n;i++){
		x[i]= read(),y[i]=read(),c[i]=read();
		add_edge(s,i,c[i],0);
		add_edge(i,s,0,0);
	}
	for (int i=1;i<=n;i++){
		int p=read(),q=read(),k=read();
		add_edge(i+n,t,k,0);
		add_edge(t,i+n,0,0);
		for (int j=1;j<=n;j++){
			add_edge(j,i+n,inf,-abs(x[j]-p)-abs(y[j]-q));
			add_edge(i+n,j,0,+abs(x[j]-p)+abs(y[j]-q));
		}
	}
	MCMF();
	printf("%lld",-mcost);
	return 0;
}

