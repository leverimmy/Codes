#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int read(){
	int w=1,x=0,ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return x*w;
} 
const int MAXN = (int)1e3+10;
int n,m,a[MAXN][MAXN],f[MAXN][MAXN][2];
//0Êú×Å£¬1ºá×Å  
int main(){
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
	n = read(),m = read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j] = read();
	memset(f,0x3f,sizeof(f));
	f[0][1][0] = f[0][1][1] = f[1][0][1] = f[1][0][0] = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int &x = f[i][j][0],&y = f[i][j][1];
			x = min(x,f[i-1][j][0]+a[i][j-1]+a[i-1][j+1]);
			x = min(x,f[i-1][j][1]+a[i-1][j+1]);
			y = min(y,f[i][j-1][1]+a[i-1][j]+a[i+1][j-1]);
			y = min(y,f[i][j-1][0]+a[i+1][j-1]);
			x += a[i][j];
			y += a[i][j];
		}
	cout<<min(f[n][m][0],f[n][m][1]);
	return 0;
}
