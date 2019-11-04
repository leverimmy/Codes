#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 2010;
const int dx[4]={-1, 1, 0, 0};
const int dy[4]={0, 0, -1, 1};
int n,m;
int a[N][N],b[N][N],f[N][N][2];
int main(){
	freopen("lemouse.in", "r", stdin);
	freopen("lemouse.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d",&a[i][j]);
			b[i][j]=a[i][j];
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			for(int k=0; k<4; k++){
				b[i][j]+=a[i+dx[k]][j+dy[k]];
			}
		}
	}
	memset(f, 0x3f, sizeof f);
	f[1][1][0]=a[1][1]+a[2][1]+a[3][1]+a[1][2]+a[2][2];
	f[1][1][1]=a[1][1]+a[2][1]+a[1][2]+a[2][2]+a[1][3];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(i-1>=1){
				f[i][j][0]=min(f[i][j][0], f[i-1][j][0]+b[i+1][j]-a[i][j]-a[i+1][j]);
				f[i][j][1]=min(f[i][j][1], f[i-1][j][0]+b[i][j+1]-a[i-1][j+1]-a[i][j]-a[i][j+1]);
			}
			if(j-1>=1){
				f[i][j][0]=min(f[i][j][0], f[i][j-1][1]+b[i+1][j]-a[i+1][j-1]-a[i][j]-a[i+1][j]);
				f[i][j][1]=min(f[i][j][1], f[i][j-1][1]+b[i][j+1]-a[i][j]-a[i][j+1]);
			}
		}
	}
	printf("%d\n",min(f[n-1][m][0], f[n][m-1][1]));
	return 0;
}

