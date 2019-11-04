#include <bits/stdc++.h>
#define maxn 300005
int n,m,u,v,p[maxn],vis[maxn]={0},ans[maxn];
std::vector<int>conj[maxn];

namespace dsu {
	int fa[maxn]={0},size[maxn]={0};
	int getf(int x){return fa[x]?fa[x]=getf(fa[x]):x;}
	void merge(int x,int y){
		int f1=getf(x),f2=getf(y);
		if (f1==f2)return;
		fa[f2]=f1;size[f1]+=size[f2];
	}
}

int main(){
	freopen("migration.in","r",stdin);
	freopen("migration.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		conj[u].push_back(v);conj[v].push_back(u);
	}for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int i=n;i>=1;i--){
		dsu::size[p[i]]=1;vis[p[i]]=1;
		for(int j=0;j<conj[p[i]].size();++j){
			if (!vis[conj[p[i]][j]])continue;
			dsu::merge(p[i],conj[p[i]][j]);
		}
		ans[i]=(dsu::size[dsu::getf(p[i])]==n-i+1);
	}for(int i=1;i<=n;++i){
		if(ans[i])printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
