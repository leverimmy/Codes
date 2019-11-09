#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 110;
int n,m;
int u[N],s[N];
int f[N][N];
bool cmp(int x,int y){
	return  x>y;
}
int main(){
	freopen("pb.in", "r", stdin);
	freopen("pb.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%d",&u[i]);
	}
	sort(u+1, u+1+n, cmp);
	for(int i=1; i<=n; i++){
		s[i]=s[i-1]+u[i];
	}
	memset(f, 0x3f, sizeof f);
	f[0][0]=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			for(int k=j; k<i; k++){
				f[i][j]=min(f[i][j], f[k-1][j-1]+i*(s[i]-s[k-1]));
			}
		}
	}
	printf("%.4lf\n",(double)f[n][m]/(double)s[n]);
	return 0;
}

