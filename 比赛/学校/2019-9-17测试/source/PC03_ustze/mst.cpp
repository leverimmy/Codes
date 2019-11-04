#include<bits/stdc++.h>
using namespace std;
#define double long double
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s; 
}
const int N=1e4+5;
int n,m;
struct edge{
	int u,v,a,b;double w;
}e[N];
int fa[N];
inline bool cmp(const edge &a,const edge &b){
	return a.w<b.w;
}
inline int findf(int x){return fa[x]==x?x:fa[x]=findf(fa[x]);}
inline bool check(double x){
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) e[i].w=e[i].a-x*e[i].b;
	sort(e+1,e+m+1,cmp);
	double res=0;
	for(int i=1;i<=m;i++){
		int fx=findf(e[i].u),fy=findf(e[i].v);
		if(fx==fy) continue;
		fa[fx]=fy;
		res+=e[i].w;
	}
	return res<=0;
}
int main(){
	freopen("mst.in","r",stdin);
	freopen("mst.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		e[i].u=read(),e[i].v=read(),e[i].a=read(),e[i].b=read();
	}
	double l=0,r=1e15,ans=0;
	for(int i=1;i<=100;i++){
		double mid=(l+r)/2;
		if(check(mid)) ans=mid,r=mid;
		else l=mid;
	}
	printf("%.5Lf",ans);
	return 0;
}

