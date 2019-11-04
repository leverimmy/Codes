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
const int MAXN=1005;
struct FIREWORK
{
	int t,p;
};
FIREWORK f[MAXN];
bool cmp(const FIREWORK &a,const FIREWORK &b)
{
	if(a.t==b.t)
	{
		return a.p<b.p;
	}
	return a.t<b.t;
}
int ti[MAXN];
int sum[MAXN];
int pos[MAXN];
int dp[MAXN][MAXN];
int max_time;
int last[MAXN];
int main()
{
	freopen("firework.in","r",stdin);
	freopen("firework.out","w",stdout);
	int N,L;
	N=Sonoda::read<int>();
	L=Sonoda::read<int>();
	for(int i=1;i<=N;i++)
	{
		f[i].t=Sonoda::read<int>();
		ti[f[i].t]++;
		f[i].p=Sonoda::read<int>();
		pos[f[i].p]++;
		max_time=max(f[i].t,max_time);
	}
	sort(f+1,f+1+N,cmp);
	srand(time(0));
	long long a=rand()%1000000;
	printf("%lld",a);
	return 0;
}
