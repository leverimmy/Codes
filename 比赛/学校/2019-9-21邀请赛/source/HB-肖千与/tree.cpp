#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int fa[N],siz[N];
struct edge{
	int u,v,w;
}e[N];
inline bool cmp(const edge & a,const edge & b){
	return a.w<b.w;
}
inline int findf(int x){return x==fa[x]?x:fa[x]=findf(fa[x]);}
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++) e[i].u=read(),e[i].v=read(),e[i].w=read();
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	int ans=0;
	for(int i=1;i<=m;i++){
		int x=findf(e[i].u),y=findf(e[i].v);
		if(x==y) continue;
		if(y==findf(1)) swap(x,y);
		fa[y]=x,siz[x]+=siz[y];
		if(x==findf(1)) ans+=siz[y]*e[i].w;
	}
	printf("%d",ans);
	return 0;
} 
