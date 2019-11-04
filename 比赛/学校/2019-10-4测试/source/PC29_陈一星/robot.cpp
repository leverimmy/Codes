#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cctype>
#define M 1010000
#define inf 0x3f3f3f3f
#define LL long long
using namespace std;
const int mod=1e9+7;
int n,m1,m2,h[M],dp[2][2][4100],tot=1,ans=inf;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while (!isdigit(s)){
		if(s=='-')f=-1;s=getchar();
	}
	while (isdigit(s))
	{
		x=(x<<1)+(x<<3)+(s^48);
		s=getchar();
	}
	return x*f;
}
struct robot{
	int h,num;
}b[M];
inline bool cmp(robot a,robot b){
	return a.h<b.h;
}
signed main(void)
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for (int i=1;i<=n;i++) h[i]=read(),b[i].h=h[i];
	h[0]=h[1];
	sort(b+1,b+n+1,cmp);
	for (int i=1;i<=n;i++){
		h[b[i].num]=tot;
		if (b[i].h!=b[i-1].h) tot+=2,h[b[i].num]=tot;
	}
	memset(dp,0x7f,sizeof(dp));
	for (int i=1;i<=tot;i++) dp[0][0][i]=dp[0][1][i]=0;
	for (int ii=1;ii<=n;ii++){
		int i=ii%2,minx1=inf,minx2=inf;
		for (int j=tot;j>=1;j--){
			if (j<h[ii]){
				dp[i][0][j]=dp[i^1][0][j]+m2;
			}
			if (j>=h[ii]){
				minx1=min(minx1,dp[i^1][0][j]);
				dp[i][0][j]=minx1+(h[ii]==j?0:m1);
			}
		}
		for (int j=1;j<=tot;j++){
			if (j<=h[ii]){
				minx2=min(minx2,dp[i^1][1][j]);
				dp[i][1][j]=minx2+((h[ii]==j?0:m2));
			}
			if (j>h[ii]){
				dp[i][1][j]=dp[i^1][1][j]+m1;
			}
		}
	}
	for (int i=1;i<=tot;i++){
		ans=min(ans,dp[n%2][0][i]);
		ans=min(ans,dp[n%2][1][i]);
	}
	printf("%d",ans);
    return 0;
}



