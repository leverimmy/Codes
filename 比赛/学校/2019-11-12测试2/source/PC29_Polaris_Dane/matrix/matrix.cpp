#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
#include<cctype>
#include<stack>
#include<queue>
#define int long long
using namespace std;
const int M=4000010;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int n,m;
int suma[900][900],sumb[900][900],a[900][900],b[900][900],sa[900][900],sb[900][900]; 
signed main(void){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			a[i][j]=read(),suma[i][j]=suma[i][j-1]+a[i][j],sa[i][j]=sa[i-1][j]+a[i][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			b[i][j]=read(),sumb[i][j]=sumb[i][j-1]+b[i][j],sb[i][j]=sb[i-1][j]+b[i][j];
	for (int i=1;i<=m;i++){
		int a=read(),b=read(),c=read(),d=read();
		if (a>c) swap(a,c);if (b>d) swap(b,d);
		int ans=0;
		for (int i=1;i<=n;i++)
			ans+=(sa[c][i]-sa[a-1][i])*(sumb[i][d]-sumb[i][b-1]);
		printf("%lld\n",ans);
	}
	return 0;
}

