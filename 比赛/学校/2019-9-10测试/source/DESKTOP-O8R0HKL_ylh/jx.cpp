#include <bits/stdc++.h>
const int inf=214748367;
int n,a[1000005],f[1000005][4],g[4],ans=-inf;
int main(){
//	freopen("jx.in","r",stdin);
//	freopen("jx.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i)scanf("%d",&a[i]);
	for (int i=0;i<=n;++i)for (int j=0;j<=3;++j)f[i][j]=-inf;
	g[0]=g[1]=g[2]=g[3]=0;
	for (int i=1;i<=n;++i){
		for (int j=0;j<=3;++j){
			f[i][j]=std::max(f[i-1][j]+a[i],j!=0?g[j-1]+a[i]:-inf);
		}for (int j=0;j<=3;++j)g[j]=std::max(g[j],f[i][j]);
		ans=std::max(ans,f[i][3]);
	}printf("%d",ans);
	return 0;
}
