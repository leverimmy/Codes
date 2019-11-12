#pragma GCC optimize("O2") 
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
} 
typedef long long ll;
const int N=805;
int n,m;
int a[N][N],b[N][N],c[N][N];
ll s[N][N];
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			b[i][j]=read();
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				c[i][j]+=a[i][k]*b[k][j];
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+c[i][j];
	for(int i=1;i<=m;i++){
		int a=read(),b=read(),c=read(),d=read();
		if(a>c) swap(a,c);if(b>d) swap(b,d);
		printf("%lld\n",s[c][d]-s[c][b-1]-s[a-1][d]+s[a-1][b-1]);
	}
	return 0;
}
