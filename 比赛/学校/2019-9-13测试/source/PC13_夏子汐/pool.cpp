#include<cstdio>
#define maxt 100005
#define mod 1000000007
using namespace std;
inline int read()
{
	register char ch=getchar();
	register int x=0;
	while(ch<'0' || ch>'9')
	{
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
int f1[maxt],f2[maxt],sum[maxt];
int main()
{
	freopen("pool.in","r",stdin);
	freopen("pool.out","w",stdout);
	register int t=read(),k=read();
	for(register int i=1;i<k;++i)
	{
		f1[i]=1;
		sum[i]=i;
	}
	f1[k]=f2[k]=1;
	sum[k]=k+1;
	for(register int i=0,max=k,a,b;i<t;++i)
	{
		a=read();
		b=read();
		if(b>max)
		{
			for(int i=max+1;i<=b;++i)
			{
				f1[i]=(f1[i-1]+f2[i-1])%mod;
				f2[i]=f1[i-k];
				sum[i]=((f1[i]+f2[i])%mod+sum[i-1])%mod;
			}
			max=b;
		}
		printf("%d\n",(sum[b]+mod-sum[a-1])%mod);
	}
	return 0;
}
