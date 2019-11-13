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
#define M 600010
#define N 50010
using namespace std;
const int inf=0x7f7f7f7f;
const int mod=1e9+7;
const double eps=1e-6;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(!isdigit(s)){if (s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int len,n;
int d[M],sum,ans;
signed main(void){
	freopen("clean.in","r",stdin);
	freopen("clean.out","w",stdout);
	len=read(),n=read();
	for (int i=1;i<=n;i++){
		int l=read(),r=read();
		d[l]++,d[r+1]--;	
	}
	sum=d[0];
	for (int i=1;i<=len;i++){
		sum+=d[i];
		if (!sum) ans++;
	}
	printf("%d",ans);
	return 0;
}
