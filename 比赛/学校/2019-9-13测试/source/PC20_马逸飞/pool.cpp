#include <cstdio>
#include <cctype>
#define il inline
#define int unsigned
#define rgi register unsigned
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
	return o1;
}
il void wi(int o1)
{
	rgi o2=o1/10;
	if(o2)
		wi(o2);
	putchar((o1-(o2<<1)-(o2<<3))^48);
}
il void wispace(int o1)
{
	wi(o1),putchar(' ');
}
il void wiendl(int o1)
{
	wi(o1),putchar('\n');
}

const int mod=1e9+7;
const int maxn=100005;
int n,k,sum[maxn],f[maxn][2];
signed main()
{
	freopen("pool.in","r",stdin);
	freopen("pool.out","w",stdout);
	n=ri(),k=ri();
	f[0][0]=1,f[0][1]=1;
	for(rgi i=1;i<=100000;++i)
	{
		if(i-1>=k)
			f[i][0]=(f[i-1][0]+f[i-1][1])%mod;
		else
			f[i][0]=f[i-1][0];
		if(i>=k)
			f[i][1]=f[i-k][0];
		sum[i]=(sum[i-1]+f[i][0]+f[i][1])%mod;
	}
	/*for(rgi i=1;i<=5;++i)
		wiendl(sum[i]-sum[i-1]);
	puts("-------");*/
	for(;n;--n)
	{
		int l=ri(),r=ri();
		wiendl(sum[r]-sum[l-1]);
	}
	return 0;
}

