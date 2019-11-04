#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<stack>
#include<vector>
#include<set>
using namespace std;
const int inf=0x7f7f7f7f;
const int M=600010;
const int N=1010;
const double eps=1e-9;
inline int read(void){
	int f=1,x=0;char s=getchar();
	while (!isdigit(s)){if (s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48),s=getchar();}
	return x*f;
}
int n;
long double a[M],b[M],t,sa[M],sb[M],ans=inf;
signed main(void){
	freopen("artist.in","r",stdin);
	freopen("artist.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++)
		scanf("%Lf%Lf",&a[i],&b[i]),sa[i]=sa[i-1]+a[i],sb[i]=sb[i-1]+b[i];
	scanf("%Lf",&t);
	for (int i=1;i<=n;i++){
		long double tmp=sa[n]*sb[i]*(sb[n]-sb[i])+sb[n]*sa[i]*(sa[n]-sa[i]);
		tmp=tmp/((sa[i]+sb[i])*(sa[n]-sa[i]+sb[n]-sb[i]));
		ans=min(ans,tmp*t);
	}
	printf("%.2Lf",ans);
	return 0;
}
