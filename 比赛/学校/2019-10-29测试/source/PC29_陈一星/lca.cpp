#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<time.h>
#define LL long long
const int inf=0x7f7f7f7f;
const int mod=1e9+7;
const double eps=1e-6;
const int M=202000;
using namespace std;
inline int read(){
	int x=0,f=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48),s=getchar();}
	return x*f;
}
int n,m,f[M][40],dep[M],head[M],cnt,root,ans=0;
struct edge{
	int to,next;
}e[M];
inline void add_edge(int u,int v){
	e[++cnt].next=head[u],head[u]=cnt,e[cnt].to=v;
}
inline void init(int x,int fa){
	for (int i=1;i<=30;i++) f[x][i]=f[f[x][i-1]][i-1];
	for (int i=head[x];i;i=e[i].next){
		if (e[i].to==fa) return;
		dep[e[i].to]=dep[x]+1;
		init(e[i].to,x);
	}
}
inline int ask(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=30;i>=0;i--){
		if (dep[f[x][i]]>=dep[y]) x=f[x][i];
		if (x==y) return x;
	}
	for (int i=30;i>=0;i--)
		if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
signed main(void){
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++){
		f[i][0]=read();
		if (!f[i][0]) f[i][0]=i,root=i;
		add_edge(i,f[i][0]),add_edge(f[i][0],i);
	}
	init(root,root);
	m=read();
	for (int i=1;i<=m;i++){
		int u=read()^ans,v=read()^ans;
		ans=ask(u,v);
		printf("%d\n",ans);
	}
	return 0;
}
