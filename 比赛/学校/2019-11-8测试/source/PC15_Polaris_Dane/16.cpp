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
int dis[M],in[M];
inline bool SPFA(int u){
	in[u]++;
	if (in[u]>n) return true;
	for (int i=head[u];i;i=e[i].nxt){
		if (dis[e[i].to]>dis[u]+e[i].val){
			dis[e[i].to]=dis[u]+e[i].val;
			if (SPFA(e[i].to)) return true;
		}
	}
	return false;
}
inline void add_edge(int u,int v,int w){
	e[++cnt].nxt=head[u],head[u]=cnt,e[cnt].to=v,e[cnt].val=w;
}
signed main(void){
	freopen("16.in","r",stdin);
	freopen("16.out","w",stdout);
	while (scanf("%d %d",&n,&m)!=EOF){
		memset(dis,0x3f,sizeof(dis)),memset(in,0,sizeof(in));
		memset(head,0,sizeof(head)),cnt=0;
		for (int i=1;i<=m;i++){
			int u=read(),v=read(),w=read();
			add_edge(u,v,w);
		}
		dis[1]=0;
		if (SPFA(1)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
