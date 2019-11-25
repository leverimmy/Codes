#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cctype>
#include<set>
#define LL long long
#define M 800010
#define N 800010
#define int long long
using namespace std;
const int inf=0x3f3f3f3f3f3f3fLL;
const double eps=1e-6;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(!isdigit(s)){if (s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int n,m,q,cnt;
int first[N],vis[N],dis[N];
int U[N],V[N],W[N];
struct edge {
	int to,_next;int wt;
}e[M<<1];
struct node{
	int id,val;
	bool operator <(const struct node&a)const{
		return val>a.val;
	}
};
void Add_Edge(int u,int v,int w) {
	e[cnt].to=v;
	e[cnt].wt=w;
	e[cnt]._next=first[u];
	first[u]=cnt++;
}
priority_queue<node>pq;
void Dijkstra(int s) {
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i) dis[i]=inf;
	node tmp;tmp.id=s,tmp.val=0;
	pq.push(tmp),dis[s]=0;
	while(!pq.empty()) {
		int x=pq.top().id;pq.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=first[x];~i;i=e[i]._next){
			if(dis[e[i].to]>dis[x]+e[i].wt) {
				dis[e[i].to]=dis[x]+e[i].wt;
				if(!vis[e[i].to]){
					tmp.id=e[i].to,tmp.val=dis[e[i].to];
					pq.push(tmp);
				}
			}
		}
	}
}
signed main(void){
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
	n=read(),m=read(),q=read();
	for(int i=1;i<=m;++i) {
		U[i]=read();
		V[i]=read();
		W[i]=read();
	}
	for(int i=1;i<=q;++i) {
		int t=read(),x=read();
		memset(first,-1,sizeof(first));
		cnt=0;
		for(int j=1;j<=m;++j){
			if(j==t)
				Add_Edge(U[j],V[j],x),Add_Edge(V[j],U[j],x);
			else
				Add_Edge(U[j],V[j],W[j]),Add_Edge(V[j],U[j],W[j]);
		}
		Dijkstra(1);
		printf("%lld\n",dis[n]);
	}
	return 0;
}
