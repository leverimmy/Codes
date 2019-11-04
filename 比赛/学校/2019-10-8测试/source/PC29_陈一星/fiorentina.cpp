#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<queue>
#include<map>
#define M 600100
#define inf 0x3f3f3f3f
#define LL long long
using namespace std;
const int mod=998244353;
int n,p,dp[100010];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while (!isdigit(s)){
		if(s=='-')f=-1;
		s=getchar();
	}
	while (isdigit(s))
	{
		x=(x<<1)+(x<<3)+(s^48);
		s=getchar();
	}
	return x*f;
}
signed main(void)
{
	freopen("fiorentina.in","r",stdin);
	freopen("fiorentina.out","w",stdout);
	n=read(),p=read();
	dp[0]=1;
	for (int i=1;i<=n;i++){
		for (int j=p;j>=i;j--){
			dp[j]+=dp[j-i];
			dp[j]%=mod;
		}
	}
	printf("%d",dp[p]);
    return 0;
}

