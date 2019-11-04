#include <bits/stdc++.h>
#define maxn 105
int n,m,p[maxn],v[maxn],G[maxn][maxn],ans=0;

int check(int S){
	int ans=0;
	for (int i=1;i<=n;++i){
		ans+=((S>>(i-1))&1)*v[i];
		int flag=0;
		for (int j=1;j<=n;++j)
			if (G[i][j]&&!((S>>(j-1))&1))flag=1;
		ans-=flag*p[i];
	}return ans;
}

int main(){
	freopen("select.in","r",stdin);
	freopen("select.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%d%d",&v[i],&p[i]);
	for (int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);G[u][v]=G[v][u]=1;
	}for (int S=0;S<(1<<n);++S){
		ans=std::max(ans,check(S));
	}printf("%d",ans);
	return 0;
}
