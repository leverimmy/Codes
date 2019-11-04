#include<bits/stdc++.h> 
using namespace std;
const int maxn=100010;
const int maxm=500010;
int n,m,ans;
int cnte;
struct edge{
	int u,v,w;
}e[maxm<<1];
void add(int u,int v,int w){
	e[++cnte]=(edge){u, v, w};
}
bool operator < (edge a,edge b){
	return a.w<b.w;
}
int fa[maxn],siz[maxn];
int find(int x){
	return x==fa[x] ? x : fa[x]=find(fa[x]);
}
void kruscal(){
	sort(e+1, e+1+cnte);
	for(int i=1; i<=n; i++){
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=1; i<=cnte; i++){
		int fu=find(e[i].u),fv=find(e[i].v),w=e[i].w;
		if(fu!=fv){
			if(find(1)==fu){
				ans+=w*siz[fv];
			}
			if(find(1)==fv){
				ans+=w*siz[fu];
			}
			fa[fu]=fv;
			siz[fv]+=siz[fu];
		}
	}
}
int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	kruscal();
	printf("%d\n",ans);
	return 0;
}
