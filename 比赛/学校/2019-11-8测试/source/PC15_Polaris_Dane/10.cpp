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
const int M=2200000;
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
int dfn[M],low[M],tot,vis[M],num;
stack<int>c;
inline void tarjan(int u){
	dfn[u]=low[u]=++tot;
	c.push(u),vis[u]=1;
	for (int i=head[u];i;i=e[i].nxt){
		if (!dfn[e[i].to]){
			tarjan(e[i].to);
			low[u]=min(low[u],low[e[i].to]);
		}
		else if (vis[e[i].to])
			low[u]=min(low[u],dfn[e[i].to]);
	}
	if (dfn[u]==low[u]){
		num++;
		while (c.top()!=u)
			c.pop();
		c.pop();
	}
}
signed main(void){
	freopen("10.in","r",stdin);
	freopen("10.out","w",stdout);
	while (scanf("%d %d",&n,&m)!=EOF){
		memset(head,0,sizeof(head)),cnt=0;
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));memset(vis,0,sizeof(vis));
		tot=0,num=0;
		for (int i=1;i<=m;i++){
			int u=read(),v=read();
			add_edge(u,v);	
		}
		for (int i=1;i<=n;i++)
			if (!dfn[i]) tarjan(i);
		printf("%d",num);
	}
	return 0;
}
