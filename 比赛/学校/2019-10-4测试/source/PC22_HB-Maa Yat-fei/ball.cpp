#include <cstdio>
#include <cctype>
#define il inline
#define int long long
#define rgi register long long
#define sp putchar(' ')
#define el putchar('\n')
using namespace std;
il int ri()
{
	register int o1=0;
	register bool o2=0;
	register char o3;
	while(!isdigit(o3=getchar()))
		o2|=o3=='-';
	while(isdigit(o3))
		o1=(o1<<1)+(o1<<3)+(o3^48),o3=getchar();
	return o2?-o1:o1;
}
il void wi(int o1)
{
	if(o1<0)
		putchar('-'),o1=-o1;
	rgi o2=o1/10;
	if(o2)
		wi(o2);
	putchar((o1-(o2<<1)-(o2<<3))^48);
}
const int mod=1e9+7;
int n,m,k;
il int pwr(int p,int q)
{
	if(q==0)
		return 1;
	if(q==1)
		return p%mod;
	int ans=pwr(p,q>>1);
	if(q&1)
		return ans*ans%mod*p%mod;
	else
		return ans*ans%mod;
}
il int inv(int p)
{
	return pwr(p,mod-2);
}
il int jc(int p)
{
	int ret=1;
	for(rgi i=2;i<=p;++i)
		ret*=i,ret%=mod;
	return ret;
}
il int c(int p,int q)
{
	return jc(p)*inv(jc(q))%mod*inv(jc(p-q))%mod;
}
signed main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=ri(),m=ri(),k=ri();
	wi(c(n-k,m-1));
	return 0;
}

