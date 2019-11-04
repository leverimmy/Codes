#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cctype>
#define M 2010000
#define inf 0x3f3f3f3f
#define LL long long
using namespace std;
const int mod=1e9+7;
LL t,k,dp[M][2],s[M];
inline int read()
{
	LL f=1,x=0;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1,s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48),s=getchar();}
	return x*f;
}
int main()
{
	freopen("pool.in","r",stdin);
	freopen("pool.out","w",stdout);
	t=read();k=read();
	dp[0][0]=1;
	for (int i=1;i<=100000;i++)
	{
		dp[i][0]+=dp[i-1][0]+dp[i-1][1];
		dp[i][0]%=mod;
		if (i-k>=0)
		dp[i][1]+=dp[i-k][0];
		dp[i][1]%=mod;
	}
	while (t--)
	{
		LL l=read(),r=read();
		LL ans=0;
		for (int i=l;i<=r;i++)
		{
			ans+=dp[i][0]+dp[i][1];
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
    return 0;
}


