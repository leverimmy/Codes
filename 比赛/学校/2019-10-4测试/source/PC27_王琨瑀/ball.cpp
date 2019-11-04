#include <bits/stdc++.h>
using namespace std;
const long long MOD=1000000007;
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
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	long long N,M,K;
	scanf("%lld%lld%lld",&N,&M,&K);
	long long up=M-1;
	long long down=N-K;
	up=min(up,down-up);
	long long ans=1;
	for(int i=1;i<=(down-up);i++)
	{
		long long a=i;
		long long b=MOD;
		long long x,y;
		Sonoda::Ex_GCD(a,b,x,y);
		while(x<0)
		{
			x+=b;
		}
		x%=b;
		ans*=x;
		ans%=MOD;
	}
	for(int i=1;i<=up;i++)
	{
		long long a=i;
		long long b=MOD;
		long long x,y;
		Sonoda::Ex_GCD(a,b,x,y);
		while(x<0)
		{
			x+=b;
		}
		x%=b;
		ans*=x;
		ans%=MOD;
	}
	for(int i=1;i<=down;i++)
	{
		ans*=i;
		ans%=MOD;
	}
	printf("%lld",ans);
	return 0;
}

