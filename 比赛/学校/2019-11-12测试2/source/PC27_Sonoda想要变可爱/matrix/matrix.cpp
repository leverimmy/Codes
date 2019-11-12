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
const long long MAXN=805;
long long a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN];
long long col[MAXN][MAXN],row[MAXN][MAXN];
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	long long N=Sonoda::read<long long>();
	long long M=Sonoda::read<long long>();
	for(long long i=1;i<=N;i++)
	{
		for(long long j=1;j<=N;j++)
		{
			a[i][j]=Sonoda::read<long long>();
		}
	}
	for(long long i=1;i<=N;i++)
	{
		for(long long j=1;j<=N;j++)
		{
			b[i][j]=Sonoda::read<long long>();
		}
	}
	for(long long i=1;i<=N;i++)
	{
		for(long long j=1;j<=N;j++)
		{
			col[i][j]=col[i-1][j]+a[i][j];
		}
	}
	for(long long i=1;i<=N;i++)
	{
		for(long long j=1;j<=N;j++)
		{
			row[i][j]=row[i][j-1]+b[i][j];
		}
	}
	for(long long i=1;i<=M;i++)
	{
		long long ans=0;
		long long a=Sonoda::read<long long>(),b=Sonoda::read<long long>(),c=Sonoda::read<long long>(),d=Sonoda::read<long long>();
		if(a>c)
		{
			Sonoda::swap(a,c);
		}
		if(b>d)
		{
			Sonoda::swap(b,d);
		}
		for(long long i=1;i<=N;i++)
		{
			ans+=(col[c][i]-col[a-1][i])*(row[i][d]-row[i][b-1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

