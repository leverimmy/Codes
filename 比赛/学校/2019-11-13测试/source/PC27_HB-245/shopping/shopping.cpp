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
const int MAXN=5005;
const int MAXM=1000005;
struct QUERY
{
	int l,r;
	int val;
};
QUERY q[MAXM];
int a[MAXN];
int book[MAXN];
int org[MAXN];
int pre[MAXN];
int N,M;
int ans;
void Update(QUERY &now)
{
	int last=0;
	int ans=0;
	for(int i=now.l;i<=now.r;i++)
	{
		if(a[i])
		{
			last+=a[i];
		}
		else
		{
			ans=max(ans,last);
			last=0;
		}
	}
	ans=max(ans,last);
	now.val=ans;
}

void Modify(const QUERY &now)
{
	for(int i=now.l;i<=now.r;i++)
	{
		a[i]=0;
	}
}

void Solve()
{
	for(int i=1;i<=N;i++)
	{
		a[i]=org[i];
	}
	int now=0;
	for(int i=1;i<=N;i++)
	{
		Update(q[book[i]]);
		now+=q[book[i]].val*q[book[i]].val;
		Modify(q[book[i]]);
	}
	ans=max(now,ans);
}

int main()
{
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	N=Sonoda::read<int>();
	M=Sonoda::read<int>();
	for(int i=1;i<=N;i++)
	{
		org[i]=Sonoda::read<int>();
		pre[i]=pre[i-1]+org[i];
	}
	for(int i=1;i<=M;i++)
	{
		q[i].l=Sonoda::read<int>();
		q[i].r=Sonoda::read<int>();
		q[i].val=pre[q[i].r]-pre[q[i].l];
	}
	for(int i=1;i<=M;i++)
	{
		book[i]=i;
	}
	do
	{
		Solve();
	}
	while(next_permutation(book+1,book+1+M));
	printf("%d",ans);
	return 0;
}

