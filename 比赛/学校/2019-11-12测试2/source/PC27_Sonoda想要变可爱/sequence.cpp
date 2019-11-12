#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
namespace Sonoda
{
	template<typename T> void swap(T &a,T &b)
	{
		T t;
		t=a;
		a=b;
		b=t;
	}
	template<typename T> T GCD(T a,T b)
	{
		if(b==0)
		{
			return a;
		}
		return GCD(b,a%b);
	}
	template<typename T>T Qpow(T a,T b,T p)
	{
		T res=1;
		while(b)
		{
			if(b&1)
			{
				res*=a;
				res%=p;
				b--;
			}
			else
			{
				a*=a;
				a%=p;
				b>>=1;
			}
		}
		return res;
	}
	template <typename T> void Ex_GCD(T a,T b,T &x,T &y)
	{
		if(b==0)
		{
			x=1;
			y=0;
			return;
		}
		Ex_GCD(b,a%b,x,y);
		T t=x;
		x=y;
		y=t-a/b*y;
	}
	template<typename T> inline T read()
	{
		T num = 0, w = 1;
		char c = 0;
		while (c != '-' && !isdigit(c)) c = getchar();
		if (c == '-') w = -1, c = getchar();
		while (isdigit(c)) num = num * 10 + c - '0', c = getchar();
		return num * w;
	}
	template<typename T> inline void write(T x)
	{
		if (x < 0) putchar('-'), x = -x;
		if (x / 10) write(x / 10);
		putchar(x % 10 + '0');
	}
}
const long long MAXN=100005;
long long sum[MAXN];
long long now,ans[MAXN];
long long a[MAXN];
long long dp[MAXN];
bool cmp(const long long &a,const long long &b)
{
	return a>b;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	long long N=Sonoda::read<long long>();
	long long K=Sonoda::read<long long>();
	if(K==1)
	{
		long long ans=-INF;
		memset(dp,-INF,sizeof(dp));
		for(long long i=1;i<=N;i++)
		{
			a[i]=Sonoda::read<long long>();
			dp[i]=max(dp[i-1]+a[i],a[i]);
			ans=max(dp[i],ans);
		}
		printf("%lld",ans);
		return 0;
	}
	for(long long i=1;i<=N;i++)
	{
		a[i]=Sonoda::read<long long>();
		sum[i]=sum[i-1]+a[i];
	}
	for(long long i=1;i<=N;i++)
	{
		for(long long j=1;j<=N;j++)
		{
			now++;
			ans[now]=sum[j]-sum[i-1];
		}
	}
	sort(ans+1,ans+now+1,cmp);
	printf("%lld",ans[K]);
	return 0;
}

