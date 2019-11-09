#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,w;
int a[N],sum[N];
double f[N][N];
inline bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
		for(int j=0;j<=w;j++) 
			f[i][j]=1e8;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=w;j++) 
			for(int k=0;k<i;k++)
				f[i][j]=min(f[i][j],f[k][j-1]+i*(sum[i]-sum[k])*1.0/sum[n]);
	}
	printf("%.4lf",f[n][w]);
	return 0;
}
