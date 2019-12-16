#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cctype>
#include<map>
#include<queue>
#include<set>
#include<stack>
const int M=300010;
const int mod=998244353;
const int inf=0x7f7f7f7f;
using namespace std;
inline int read(void){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<3)+(x<<1)+(s^48),s=getchar();}
	return x*f;	
}
struct edge{
	int to,from,val,nxt;	
	bool operator <(const edge&a)const{
		return val<a.val;
	}
}e[M<<1],t[M];
int cnt,cnte,head[M];
inline void add_edge(int u,int v,int w){
	e[++cnt].to=v,e[cnt].from=u,e[cnt].val=w;
}
inline void add_tree(int u,int v,int w){
	t[++cnte].nxt=head[u],head[u]=cnte,t[cnte].to=v,t[cnte].val=w;
}
int n,m,fa[M];
inline int find(int a){
	return a==fa[a]?fa[a]:fa[a]=find(fa[a]);	
}
inline void kruskal(void){
	sort(e+1,e+m+1);int ans=0;
	for (int i=1;i<=m;i++){
		int u=e[i].from,v=e[i].to;
		int X=find(u),Y=find(v);
		if (X==Y) continue;
		fa[X]=Y;
		add_tree(u,v,e[i].val),add_tree(v,u,e[i].val);
		ans++;
		if (ans==n-1) return;
	}
}
int dep[M],f[M][31],maxx[M][31];
inline void init(int rt,int fa){
	dep[rt]=dep[fa]+1,f[rt][0]=fa;
	for (int i=1;i<=30;i++) f[rt][i]=f[f[rt][i-1]][i-1],maxx[rt][i]=max(maxx[rt][i-1],maxx[f[rt][i-1]][i-1]);
	for (int i=head[rt];i;i=t[i].nxt){
		if (t[i].to==fa) continue;
		maxx[t[i].to][0]=t[i].val,init(t[i].to,rt);
	}
}
inline int ask(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int ans=0;
	for (int i=30;i>=0;i--){
		if (dep[f[x][i]]>=dep[y]) ans=max(ans,maxx[x][i]),x=f[x][i];
		if (x==y) return ans;
	}
	for (int i=30;i>=0;i--)
		if (f[x][i]!=f[y][i])
			ans=max(ans,max(maxx[x][i],maxx[y][i])),x=f[x][i],y=f[y][i];
	ans=max(ans,max(maxx[x][0],maxx[y][0]));
	return ans;
}
signed main(void){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		add_edge(u,v,w);
	}
	for (int i=1;i<=n;i++) fa[i]=i;
	kruskal();
	init(1,0);
	int p=read();
	for (int i=1;i<=p;i++){
		int a=read(),b=read();
		printf("%d\n",ask(a,b));	
	}
	return 0;	
}
