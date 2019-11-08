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
int n,m,head[M],cnt;
struct edge{
	int nxt,to; 
}e[M];
inline void add_edge(int u,int v){
	e[++cnt].nxt=head[u],head[u]=cnt,e[cnt].to=v;
}
int dfn[M],low[M],tot,ans;
inline void tarjan(int u,int from){
	dfn[u]=low[u]=++tot;
	for (int i=head[u];i;i=e[i].nxt){
		if ((i^1)==from||i==from) continue;
		if (!dfn[e[i].to]){
			tarjan(e[i].to,i);
			low[u]=min(low[u],low[e[i].to]);
			if (low[e[i].to]>dfn[u]) ans++;
		}
		low[u]=min(low[u],dfn[e[i].to]);
	}
}
signed main(void){
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	while (scanf("%d %d",&n,&m)!=EOF){
		memset(dfn,0,sizeof(dfn)),memset(low,0,sizeof(low));tot=0;
		memset(head,0,sizeof(head)),cnt=1,ans=0;
		for (int i=1;i<=m;i++){
			int u=read(),v=read();
			add_edge(u,v),add_edge(v,u);
		}
		if (n==1){
			printf("0");
			return 0;
		}
		tarjan(1,-1);
		printf("%d\n",ans);
	}	
	return 0;
}
