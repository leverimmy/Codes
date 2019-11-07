#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; 
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
const int N=405;
int n,m,s;
int v[N][N],w[N][N],f[2][N][N];
inline void cmax(int &x,int y){
	if(y>x) x=y;
}
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n=read(),m=read(),s=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			v[i][j]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			w[i][j]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<=s;k++){
				cmax(f[i&1][j][k],f[(i-1)&1][j][k]);
				cmax(f[i&1][j][k],f[i&1][j-1][k]);
				if(k>=v[i][j]) {
					cmax(f[i&1][j][k],f[(i-1)&1][j][k-v[i][j]]+w[i][j]);
					cmax(f[i&1][j][k],f[i&1][j-1][k-v[i][j]]+w[i][j]);
				}
			}
	printf("%d",f[n&1][m][s]);
    return 0;
}
