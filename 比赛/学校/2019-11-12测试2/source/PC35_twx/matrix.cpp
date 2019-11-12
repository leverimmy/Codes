#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 810;
int n,m;
int a[N][N],b[N][N];
int sa[N][N],sb[N][N];
signed main(){
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%lld",&b[i][j]);
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			sa[i][j]=sa[i-1][j]+a[i][j];
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			sb[i][j]=sb[i][j-1]+b[i][j];
		}
	}
	for(int i=1; i<=m; i++){
		int xl,xr,yl,yr,ans=0;
		scanf("%lld%lld%lld%lld",&xl,&yl,&xr,&yr);
		if(xl>xr){
			swap(xl, xr);
		}
		if(yl>yr){
			swap(yl, yr);
		}
		for(int i=1; i<=n; i++){
			ans+=(sa[xr][i]-sa[xl-1][i])*(sb[i][yr]-sb[i][yl-1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

