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
const int M=400001;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int head[M],cnt;
struct edge{
	int to,nxt;	
}e[M];
inline void add_edge(int u,int v){
	e[++cnt].nxt=head[u],head[u]=cnt,e[cnt].to=v;	
}
int end,maxpos,maxdis,f[M][31],dep[M],ans,d[M],a[M],tmp,s[M];
inline void init(int rt,int dis){
	dep[rt]=dep[f[rt][0]]+1;
	for (int i=1;i<=30;i++) f[rt][i]=f[f[rt][i-1]][i-1];
	if (maxdis<dis) maxdis=dis,maxpos=rt;
	for (int i=head[rt];i;i=e[i].nxt){
		if (e[i].to==f[rt][0]) continue;
		f[e[i].to][0]=rt;
		init(e[i].to,dis+a[e[i].to]);	
	}
}
inline int ask(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=30;i>=0;i--){
		if (dep[f[x][i]]>=dep[y]) x=f[x][i];
		if (x==y) return x;
	}
	for (int i=30;i>=0;i--)
		if (f[x][i]==f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
inline void dfs(int rt,int dis,int fa){
	if (maxdis<dis) maxdis=dis,end=rt;
	for (int i=head[rt];i;i=e[i].nxt){
		if (e[i].to==fa) continue;
		dfs(e[i].to,dis+a[e[i].to],rt);	
	}
}
inline void dfs_get(int rt){
	s[rt]=d[rt];
	for (int i=head[rt];i;i=e[i].nxt){
		if (e[i].to==f[rt][0]) continue;
		dfs_get(e[i].to);
		s[rt]+=s[e[i].to];
	}
}
int vis[M];
inline void get_ans(int rt,int dis,int fa){
	vis[rt]=1;
	if (maxdis<dis) maxdis=dis,maxpos=rt;
	for (int i=head[rt];i;i=e[i].nxt){
		if (e[i].to==fa||s[e[i].to]) continue;
		get_ans(e[i].to,dis+a[e[i].to],rt);
	}
}
inline void find_far(int rt,int dis,int fa){
	if (maxdis<dis) maxdis=dis,end=rt;
	for (int i=head[rt];i;i=e[i].nxt){
		if (e[i].to==fa||s[e[i].to]) continue;
		find_far(e[i].to,dis+a[e[i].to],rt);
	}
}
signed main(void){
	freopen("attack.in","r",stdin);
	freopen("attack.out","w",stdout);
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n-1;i++){
		int u=read(),v=read();
		add_edge(u,v),add_edge(v,u);	
	}
	init(1,a[1]);
	maxdis=0;
	dfs(maxpos,a[maxpos],0);
	ans=maxdis;
	int lca=ask(maxpos,end);
	d[lca]--,d[f[lca][0]]--,d[maxpos]++,d[end]++;
	dfs_get(1);
	for (int i=1;i<=n;i++)
		if (!s[i]&&!vis[i]){
			maxdis=0;
			get_ans(i,a[i],0);
			find_far(maxpos,a[maxpos],0);
			tmp=max(tmp,maxdis);
		}
	printf("%d",ans+tmp);
	return 0;
}
