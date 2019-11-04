#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cctype>
#define M 10100000
#define inf 0x3f3f3f3f
#define LL long long
using namespace std;
const int mod=1e9+7;
LL n,m,k;
inline LL read()
{
	LL f=1,x=0;char s=getchar();
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
inline LL qpow(LL a,LL b){
	LL ans=1;
	while (b>0){
		if (b&1) ans*=a,ans%=mod;
		b>>=1;
		a*=a,a%=mod;
	}
	return ans;
}
inline LL cal(LL n,LL m){
	LL ans=1;
	for (int i=1;i<=m;i++){
		ans*=(n-i+1);
		ans%=mod;
		ans*=qpow(i,mod-2);
		ans%=mod;
	}
	return ans;
}
signed main(void)
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(),m=read(),k=read();
	printf("%lld",cal(n-k,m-1));
    return 0;
}



