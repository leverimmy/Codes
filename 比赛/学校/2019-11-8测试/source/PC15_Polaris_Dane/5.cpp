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
int n,m,ans,cnt;
struct edge{
	int from,to,val;
	bool operator <(const edge&a)const{
		return val<a.val;
	}
}e[M];
inline void add_edge(int u,int v,int w){
	e[++cnt].from=u,e[cnt].to=v,e[cnt].val=w;
}
int fa[M];
inline int find(int x){
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);	
}
int cnte;
inline void kruskal(void){
	sort(e+1,e+m+1);
	for (int i=1;i<=m;i++){
		int X=find(e[i].to),Y=find(e[i].from);
		if (X==Y) continue;
		ans+=e[i].val;
		fa[X]=Y;
		cnte++;
		if (cnte==n-1) return;
	}
}
signed main(void){
	freopen("5.in","r",stdin);
	freopen("5.out","w",stdout);
	while (scanf("%d %d",&n,&m)!=EOF){
		cnt=0,cnte=0,ans=0;
		for (int i=1;i<=n;i++) fa[i]=i;
		for (int i=1;i<=m;i++){
			int u=read(),v=read(),w=read();
			add_edge(u,v,w);	
		}
		kruskal();
		printf("%d",ans);
	}
	return 0;
}
