#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<time.h>
#define M 101000
#define rgi register int
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=998244353;
inline int read(){
	int x=0,f=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48),s=getchar();}
	return x*f;
}
int n,k,x[M],y[M],dp[1010][510],ans=inf;
signed main(void){
	freopen("transport.in","r",stdin);
	freopen("transport.out","w",stdout);
	n=read(),k=read();
	for (int i=1;i<=n;i++)
		x[i]=read(),y[i]=read();
	memset(dp,0x7f,sizeof(dp));
	for (int i=0;i<=k;i++) dp[1][i]=0;
	for (int i=2;i<=n;i++){
		for (int j=0;j<=k;j++){
			dp[i][j]=dp[i-1][j]+abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
			for (int t=max(0ll,i-j-1);t<i;t++){
				dp[i][j]=min(dp[i][j],dp[t][j-(i-t-1)]+abs(x[i]-x[t])+abs(y[i]-y[t]));
			}
		}
	}
	for (int i=0;i<=k;i++)
		ans=min(ans,dp[n][i]);
	printf("%lld",ans);
	return 0;
}
