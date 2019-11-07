#include <bits/stdc++.h>

int f[2][405][405],n,m,s,w[405][405],v[405][405];

int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)scanf("%d",&w[i][j]);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)scanf("%d",&v[i][j]);
	std::memset(f,0,sizeof(f));
	for(int i=1;i<=n;++i){
		int x=i%2;int y=x^1;
		std::memset(f[x],0,sizeof(f[x]));
		for(int j=1;j<=m;++j)
			for(int k=0;k<=s;++k){
				f[x][j][k]=std::max(f[y][j][k],f[x][j-1][k]);
				if (k>=w[i][j])f[x][j][k]=std::max(f[x][j][k],std::max(f[x^1][j][k-w[i][j]]+v[i][j],f[x][j-1][k-w[i][j]]+v[i][j]));
			}
	}
	int ans=0;
	for(int i=0;i<=s;++i)ans=std::max(ans,f[n%2][m][i]);
	printf("%d",ans);
	return 0;
}
