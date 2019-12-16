#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
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
const int MAXN=1000005;
struct POINT
{
	int x,y;
};
POINT a[MAXN];
int dp[MAXN];
int c[MAXN],N;
int lowbit(int x)
{
	return x&(-x);
}
void Add(int x,int t)
{
	while(x<=N)
	{
		c[x]+=t;
		x+=lowbit(x);
	}
}
int Sum(int x)
{
	int res=0;
	while(x)
	{
		res+=c[x];
		x-=lowbit(x);
	}
	return res;
}
int _array[MAXN],len;
int Find(int x)
{
	return lower_bound(_array+1,_array+1+len,x)-_array;
}
int ans=-INF;
int main()
{
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	N=Sonoda::read<int>();
	for(int i=1;i<=N;i++)
	{
		a[i].x=Sonoda::read<int>();
		a[i].y=Sonoda::read<int>();
	}
	for(int i=1;i<=N;i++)
	{
		dp[i]=1;
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[i].x>a[j].x&&a[i].y>a[j].y)
			{
				dp[i]=max(dp[j]+1,dp[i]);
			}
		}
		ans=max(dp[i],ans);
	}
	printf("%d",ans);
    return 0;
}


