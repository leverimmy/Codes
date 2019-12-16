#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
namespace Sonoda
{
	template<typename T> void swap(T &a,T &b){T t;t=a;a=b;b=t;}
	template<typename T> T GCD(T a,T b){if(b==0){return a;}return GCD(b,a%b);}
	template<typename T>T Qpow(T a,T b,T p){T res=1;while(b){if(b&1){res*=a;res%=p;b--;}else{a*=a;a%=p;b>>=1;}}return res;}
	template<typename T> void Ex_GCD(T a,T b,T &x,T &y){if(b==0){x=1;y=0;return;}Ex_GCD(b,a%b,x,y);T t=x;x=y;y=t-a/b*y;}
	template<typename T> inline T read(){T num = 0, w = 1;char c = 0;while (c != '-' && !isdigit(c)) c = getchar();if (c == '-') w = -1, c = getchar();while (isdigit(c)) num = num * 10 + c - '0', c = getchar();return num * w;}
	template<typename T> inline void write(T x){if (x < 0) putchar('-'), x = -x;if (x / 10) write(x / 10);putchar(x % 10 + '0');}
}
const long long MAXN=100005;
const long long BEGIN=10000;
long long l=BEGIN,r=BEGIN-1;
int a[MAXN];
int main()
{
	freopen("dance.in","r",stdin);
	freopen("dance.out","w",stdout);
	long long N=Sonoda::read<long long>();
	for(long long i=1;i<=N;i++)
	{
		r++;
		a[r]=0;
	}
	long long M=Sonoda::read<long long>();
	for(long long t=1;t<=M;t++)
	{
		long long opt=Sonoda::read<long long>();
		if(opt==1)
		{
			long long k=Sonoda::read<long long>();
			for(long long i=l-1;i>=l-k;i--)
			{
				a[i]=0;
			}
			l-=k;
		}
		if(opt==2)
		{
			long long k=Sonoda::read<long long>();
			for(long long i=r+1;i<=r+k;i++)
			{
				a[i]=0;
			}
			r+=k;
		}
		if(opt==3)
		{
			long long b=Sonoda::read<long long>();
			long long s=Sonoda::read<long long>();
			for(long long i=l;i<=r;i++)
			{
				a[i]+=b+s*(i-l);
			}
		}
		long long now=INF;
		long long aim=0;
		for(long long i=l;i<=r;i++)
		{
			if(a[i]<now)
			{
				aim=i;
				now=a[i];
			}
		}
		printf("%lld %lld\n",aim-l+1,now);
	}
    return 0;
}

