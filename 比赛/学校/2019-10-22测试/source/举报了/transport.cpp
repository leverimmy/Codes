#include <bits/stdc++.h>
#define maxn 1005
int n,k,x[maxn],y[maxn],f[maxn][maxn];
int dis(int a,int b){return std::abs(x[a]-x[b])+std::abs(y[a]-y[b]);}

int main(){
	freopen("transport.in","r",stdin);
	freopen("transport.out","w",stdout);
	scanf("%d%d",&n,&k);//k=1;
	for(int i=1;i<=n;++i){
		scanf("%d%d",&x[i],&y[i]);
	}std::memset(f,63,sizeof(f));f[1][0]=0;
	for(int i=2;i<=n;++i){
		for(int l=0;l<=k;++l)
		for(int j=0;j<=l&&i-1-j>=1;++j)
			f[i][l]=std::min(f[i][l],f[i-j-1][l-j]+dis(i,i-j-1));
		//for(int j=0;j<=k;++j)printf("%d ",f[i][j]);printf("\n");
	}int ans=1e8;
	for(int i=0;i<=k;++i)ans=std::min(f[n][i],ans);
	printf("%d",ans);
	return 0;
}
