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
int n,m,ans,cnt,head[M];
struct edge{
	int nxt,to,val;
}e[M];
struct node{
	int num,dis;
	bool operator <(const node&a)const{
		return a.dis<dis;
	}
};
priority_queue<node>pq;
int dis[M],c[M];
inline void dij(){
	memset(dis,0x7f,sizeof(dis));
	memset(c,0,sizeof(c));
	dis[1]=0;pq.push(node{1,0});
	while (!pq.empty()){
		node h=pq.top();pq.pop();
		int p=h.num;
		if (c[p]) continue;
		c[p]=1;
		for (int i=head[p];i;i=e[i].nxt){
			if (dis[e[i].to]>dis[p]+e[i].val){
				dis[e[i].to]=dis[p]+e[i].val;
				if (!c[e[i].to]) pq.push(node{e[i].to,dis[e[i].to]});
			}
		}
	}
}
inline void add_edge(int u,int v,int w){
	e[++cnt].nxt=head[u],head[u]=cnt,e[cnt].to=v,e[cnt].val=w;
}
signed main(void){
	freopen("6.in","r",stdin);
	freopen("6.out","w",stdout);
	while (scanf("%d %d",&n,&m)!=EOF){
		memset(head,0,sizeof(head)),cnt=0;
		for (int i=1;i<=m;i++){
			int u=read(),v=read(),w=read();
			add_edge(u,v,w),add_edge(v,u,w);
		}
		dij();
		printf("%d",dis[n]);
	}
	return 0;
}
