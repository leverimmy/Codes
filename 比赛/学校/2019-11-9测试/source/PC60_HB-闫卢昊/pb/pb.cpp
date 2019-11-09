#include <bits/stdc++.h>

int n,w,f[105][105],sum[105]={0},u[105];

int main(){
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;++i)scanf("%d",&u[i]);
	std::sort(u+1,u+n+1);std::reverse(u+1,u+n+1);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+u[i];
	std::memset(f,63,sizeof(f));f[0][0]=0;
	for(int i=1;i<=n;++i){
		//f[i]=1e9;
		for(int j=1;j<=w;++j)
			for(int k=0;k<i;++k)f[i][j]=std::min(f[i][j],f[k][j-1]+i*(sum[i]-sum[k]));
	}printf("%.4f",f[n][w]/(double)sum[n]);
	return 0;
}
