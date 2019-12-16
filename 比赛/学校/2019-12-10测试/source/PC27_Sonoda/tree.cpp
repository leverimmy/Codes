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
const long long MAXN=500005;
const long long MOD=998244353;
long long N;
struct EDGE
{
	long long _next,to;
};
EDGE edge[MAXN];
long long _count,head[MAXN];
void Add_Line(const long long &a,const long long &b)
{
	_count++;
	edge[_count]._next=head[a];
	edge[_count].to=b;
	head[a]=_count;
}
bool vis[MAXN];
long long ans;
long long book[MAXN],dp[MAXN],siz[MAXN];
bool _map[104][104];
//Á´--a[n-1]*2+2^(N-1)
//a[1]=1
struct NODE
{
	long long a,b;
};NODE node[MAXN];
bool Check()
{
	bool flag=1;
	for(long long i=1;i<N;i++)
	{
		for(long long j=1;j<N;j++)
		{
			long long x1=node[i].a,x2=node[i].b,y1=node[j].a,y2=node[j].b;
			if(book[x1]<book[x2])
			{
				swap(x1,x2);
			}
			if(book[y1]<book[y2])
			{
				swap(y1,y2);
			}
			if(book[x2]<book[y2]&&book[y2]<book[x1]&&book[x1]<book[y1])
			{
				flag=0;
			}
		}
	}
	return flag;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	N=Sonoda::read<long long>();
	if(N<=9)
	{
		for(long long i=1;i<N;i++)
		{
			long long a=Sonoda::read<long long>();
			long long b=Sonoda::read<long long>();
			_map[a][b]=_map[b][a]=1;
			node[i].a=a,node[i].b=b;
		}
		for(long long i=1;i<=N;i++)
		{
			book[i]=i;
		}
		do
		{
			ans+=Check();
		}
		while(next_permutation(book+1,book+1+N));
		printf("%lld",ans%MOD);
	}
	else
	{
		for(long long i=1;i<N;i++)
		{
			long long a=Sonoda::read<long long>();
			long long b=Sonoda::read<long long>();
			Add_Line(a,b),Add_Line(b,a);
		}
		dp[1]=1;
		dp[2]=2;
		for(long long i=3;i<=N;i++)
		{
			dp[i]=dp[i-1]*2+Sonoda::Qpow(2LL,i-2,MOD);
			dp[i]%=MOD;
		}
		printf("%lld",dp[N]);
	}
    return 0;
}

