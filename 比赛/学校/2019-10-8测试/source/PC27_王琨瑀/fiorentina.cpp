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
const long long MAXN=50000;
const long long MOD=998244353;
long long v[MAXN],p[MAXN];
long long dp[MAXN];
long long book[MAXN];
long long _count;
long long N,M;
void DFS(long long now)
{
	if(now==N)
	{
		long long ans=1;
		for(long long i=1;i<=N;i++)
		{
			if(book[i])
			{
				ans*=p[i];
			}
		}
		_count++;
		v[_count]=ans;
		return;
	}
	book[now+1]=1;
	DFS(now+1);
	book[now+1]=0;
	DFS(now+1);
}
int main()
{
	freopen("fiorentina.in","r",stdin);
	freopen("fiorentina.out","w",stdout);	
	N=Sonoda::read<long long>();
	M=Sonoda::read<long long>();
	for(long long i=1;i<=N;i++)
	{
		p[i]=(1<<i)-1;
	}
	dp[0]=1;
	DFS(0);
	for(long long i=1;i<=_count;i++)//Ç°i¸öÊý 
	{
		for(long long j=M;j>=v[i];j--)
		{
			dp[j]+=dp[j-v[i]]%MOD;
			dp[j]%=MOD;
		}
	}
	printf("%lld",dp[M]%MOD);
	return 0;
}

