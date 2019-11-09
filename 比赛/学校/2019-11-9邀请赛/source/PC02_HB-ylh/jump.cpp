#include <bits/stdc++.h>
#define ll long long
#define maxn 50005
int n,k,u,v,son[maxn]={0},depth[maxn]={0},height[maxn];
ll f[maxn][205]={0},g[maxn][205]={0},ans=0;
std::vector<int>conj[maxn];

void dfs1(int u,int fa){
	depth[u]=depth[fa]+1;height[u]=depth[u];
	for(int i=0;i<conj[u].size();++i){
		int v=conj[u][i];
		if (v==fa)continue;
		dfs1(v,u);
		if (depth[v]>depth[son[u]])son[u]=v;
		height[u]=std::max(height[u],height[v]);
	}//if (son[u])height[u]=height[son[u]];
}

void dfs(int u,int fa){
	f[u][0]=1;
	if (son[u]){
		int v=son[u];
		dfs(v,u);
		for(register int l=0;l<std::min(k,height[v]-depth[u]);++l)
			ans+=((l+1)/k+((l+1)%k>0))*f[u][0]*f[v][l]+f[u][0]*g[v][l]+g[u][0]*f[v][l];
		for(int j=0;j<k;++j){g[u][(j+1)%k]+=g[v][j]+(j+1)/k*f[v][j];f[u][(j+1)%k]+=f[v][j];}
	}
	for(int i=0;i<conj[u].size();++i){
		int v=conj[u][i];
		if (v==fa||v==son[u])continue;
		dfs(v,u);
		for(int j=0;j<std::min(k,height[u]);++j)
			for(register int l=0;l<std::min(k,height[v]-depth[u]);++l)
				ans+=((j+l+1)/k+((j+l+1)%k>0))*f[u][j]*f[v][l]+f[u][j]*g[v][l]+g[u][j]*f[v][l];
		for(int j=0;j<k;++j){g[u][(j+1)%k]+=g[v][j]+(j+1)/k*f[v][j];f[u][(j+1)%k]+=f[v][j];}
	}//printf("%d\n",u);
	///for(int i=0;i<k;++i)printf("%d %d\n",f[u][i],g[u][i]);
	//printf("=%lld\n",ans);
}

int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		conj[u].push_back(v);conj[v].push_back(u);
	}dfs1(1,0);dfs(1,0);
	printf("%lld",ans);
	return 0;
}


