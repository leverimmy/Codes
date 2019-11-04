#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#define M 2600001
#define N 110000
const int inf=0x3f3f3f3f;
using namespace std;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){
		if (s=='-') f=-1;
		s=getchar();
	}
	while (isdigit(s)){
		x=(x<<1)+(x<<3)+(s^48);
		s=getchar();
	}
	return x*f;
}
struct node{
	int num,dis;
	bool operator <(const node&a)const{
		return a.dis<dis;
	}
};
priority_queue<node>pq;

int cnt,head[N];
struct edge{
	int to,next,val;
}e[M];
inline void add_edge(int u,int v,int w){
	e[++cnt].next=head[u];e[cnt].to=v;e[cnt].val=w;
	head[u]=cnt;
}

int n,m,k;
int dis[N],c[N],pre[N],ans;
inline void dij(){
	memset(dis,0x7f,sizeof(dis));
	pq.push(node{1,0});
	dis[1]=0;
	while (!pq.empty()){
		node h=pq.top();
		pq.pop();
		int p=h.num;
		if (c[p]) continue;
		c[p]=1;
		ans+=e[pre[p]].val;
		for (int i=head[p];i;i=e[i].next){
			if (dis[e[i].to]>dis[p]+e[i].val){
				pre[e[i].to]=i;
				dis[e[i].to]=dis[p]+e[i].val;
				if (!c[e[i].to]){
					pq.push(node{e[i].to,dis[e[i].to]});
				}
				continue;
			}
			if (dis[e[i].to]==dis[p]+e[i].val&&e[pre[e[i].to]].val>e[i].val)
				pre[e[i].to]=i;
		}
	}
}

signed main(void){
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		add_edge(u,v,w),add_edge(v,u,w);
	}
	dij();
	printf("%d",ans);
	return 0;
}
