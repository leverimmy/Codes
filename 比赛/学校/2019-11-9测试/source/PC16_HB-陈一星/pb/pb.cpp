#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<set>
#include<queue>
#include<map>
#include<stack>
using namespace std;
const int M=1000;
const int inf=0x7f7f7f7f;
const double eps=1e-9;
inline int read(void){
	int x=0,f=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int val[M];
double sum[M];
double D[M][M];
inline bool cmp(int a,int comp){
	return a>comp;
}
int n,m,tot;
signed main(void){
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		val[i]=read();
		tot+=val[i];
	}
	sort(val+1,val+1+n,cmp);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+((double)val[i])/tot;
	for(int i=1;i<=n;i++) D[i][1]=sum[i]*i;
	for(int div=2;div<=m;div++)
		for(int i=div;i<=n;i++){
			D[i][div]=inf;
			for(int k=div-1;k<i;k++)
				D[i][div]=min(D[i][div],D[k][div-1]+i*(sum[i]-sum[k]));
		}
	printf("%.4lf\n",D[n][m]);
	return 0;
}
