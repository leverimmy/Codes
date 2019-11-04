#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1000010;
const int INF = 0x3f3f3f3f;
int n;
int a[N],f[N][4][2];
int main(){
	freopen("jx.in", "r", stdin);
	freopen("jx.out", "w", stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	for(int i=0; i<=n; i++){
		for(int j=0; j<=3; j++){
			for(int k=0; k<=1; k++){
				f[i][j][k]=-INF;
			}
		}
	}
	f[0][0][0]=0;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=3; j++){
			f[i][j][0]=max(f[i-1][j][0], f[i-1][j][1]);//ฒปัก
			f[i][j][1]=max(f[i][j][1], f[i-1][j][1]+a[i]);//ัก
			if(j>0){
				f[i][j][1]=max(f[i][j][1], max(f[i-1][j-1][0]+a[i], f[i-1][j-1][1]+a[i]));
			}
		}
	}
	printf("%d\n",max(f[n][3][1], f[n][3][0]));
}

