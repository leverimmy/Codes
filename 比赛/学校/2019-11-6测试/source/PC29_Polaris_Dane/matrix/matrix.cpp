#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cctype>
#include<set>
#define LL long long
#define M 200100
#define N 50010
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-6;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(!isdigit(s)){if (s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int n,m,s,w[500][500],v[500][500],dp[2][500][500];
signed main(void){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n=read(),m=read(),s=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			w[i][j]=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			v[i][j]=read();
	for (int ii=1;ii<=n;ii++)
		for (int j=1;j<=m;j++)
			for (int k=0;k<=s;k++){
				int i=ii%2;
				dp[i][j][k]=max(dp[i^1][j][k],dp[i][j-1][k]);
				if (k>=w[i][j]){
					dp[i][j][k]=max(dp[i][j][k],dp[i^1][j][k-w[ii][j]]+v[ii][j]);
					dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-w[ii][j]]+v[ii][j]);
				}
			}
	printf("%d",dp[n%2][m][s]);
	return 0;
}

