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
const int MAXN=1000005;
int a[MAXN];
int c[MAXN],sum[MAXN],_count;
bool cmp(const int &a,const int &b)
{
	return a>b;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int N=Sonoda::read<int>();
	int K=Sonoda::read<int>();
	int L=Sonoda::read<int>();
	int R=Sonoda::read<int>();
	for(int i=1;i<=N;i++)
	{
		a[i]=Sonoda::read<int>();
		sum[i]=sum[i-1]+a[i];
	}
	for(int len=L;len<=R;len++)
	{
		for(int i=1;i<=N;i++)
		{
			int s=0;
			if(i+len-1>N)
			{
				continue;
			}
			s=sum[i+len-1]-sum[i-1];
			_count++;
			c[_count]=s;
		}
	}
	sort(c+1,c+1+_count,cmp);
	int ans=0;
	for(int i=1;i<=K;i++)
	{
		ans+=c[i];
	}
	printf("%d",ans);
	return 0;
}

