#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
const int N = 510;
int n,k;
int f[N][N];
int x[N],y[N];
int dis[N][N];
int main(){
	freopen("transport.in", "r", stdin);
	freopen("transport.out", "w", stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			dis[j][i]=dis[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
		}
	}
	memset(f, 0x3f, sizeof f);
	for(int i=0; i<=k; i++){
		f[1][i]=0;
	}
	for(int i=2; i<=n; i++){
		for(int j=0; j<=k; j++){
			for(int p=0; p<=j; p++){
				int q=j-p,z=i-p-1;
				if(z>=1){
					f[i][j]=min(f[i][j], f[z][q]+dis[z][i]);
				}
			}
		}
	}
	printf("%d\n",f[n][k]);
	return 0;
}

