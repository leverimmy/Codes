#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[900][900],b[900][900],sum1[900][900],sum2[900][900];
signed main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%lld",&b[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum1[i][j]=sum1[i-1][j]+a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum2[i][j]=sum2[i][j-1]+b[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		int x1,x2,y1,y2;
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		if(x1>x2) swap(x1,x2);
		if(y1>y2) swap(y1,y2);
		int res=0;
		for(int j=1;j<=n;j++){
			res+=(sum1[x2][j]-sum1[x1-1][j])*(sum2[j][y2]-sum2[j][y1-1]);
		}
		printf("%lld\n",res);
	}
}
