#include <bits/stdc++.h>
#define INF 0x7f7f7f7f
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

const int MAXN=500005;
double sum1[MAXN],sum2[MAXN];
double ans=INF;
int ansin=INF;
int main()
{
	freopen("artist.in","r",stdin);
	freopen("artist.out","w",stdout);
	int N=Sonoda::read<int>();
	for(int i=1;i<=N;i++)
	{
		double a,b;
		scanf("%lf%lf",&a,&b);
		sum1[i]=sum1[i-1]+a;
		sum2[i]=sum2[i-1]+b;
	}
	double T;
	scanf("%lf",&T);
	for(int i=1;i<=N;i++)
	{
		//ÔÚi´¦¸Ä
		double bef1=sum1[i-1];
		double aft1=sum1[N]-sum1[i-1];
		double bef2=sum2[i-1];
		double aft2=sum2[N]-sum2[i-1];
		double a1,a2,b1,b2;
		a1=T*(bef2)/(bef1+bef2);
		b1=T-a1;
		a2=T*(aft2)/(aft1+aft2);
		b2=T-a2;
//		double a=(aft2+bef1)*T/(aft1+bef2+aft2+bef1);
		ans=min(ans,max(a1*bef1,b1*bef2)+max(a2*aft1,b2*aft2));
//		ans=min(ans,max(a*(aft1+bef2),(T-a)*(aft2+bef1)));
	}
	printf("%.2lf",ans);
	return 0;
}

