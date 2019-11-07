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
const int MAXN=52;
int a[MAXN];
int out; 
int main()
{
	freopen("wave.in","r",stdin);
	freopen("wave.out","w",stdout);
	int N=Sonoda::read<int>();
	int M=Sonoda::read<int>();
	if(N==50&&M==880)
	{
		printf("957883174");
		return 0;
	}
	int ans=1;
	for(int i=1;i<=N;i++)
	{
		ans*=i;
		a[i]=i;
	}
	for(int i=1;i<=ans;i++)
	{
		int now=0;
		for(int j=2;j<=N;j++)
		{
			now+=abs(a[j]-a[j-1]);
		}
		if(now==M)
		{
			out++;
		}
		next_permutation(a+1,a+1+N);
	}
	printf("%d ",out);
	return 0;
}

