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

const long long MAXN=4000005;

long long heap[MAXN],siz;

void push(long long x)
{
	siz++;
	heap[siz]=x;
	long long NowNode=siz;
	while(NowNode>>1)
	{
		long long NextNode=NowNode>>1;
		if(heap[NextNode]>heap[NowNode])
		{
			Sonoda::swap(heap[NextNode],heap[NowNode]);
			NowNode=NextNode;
		}
		else
		{
			break;
		}
	}
}

void pop()
{
	Sonoda::swap(heap[siz],heap[1]);
	siz--;
	long long NowNode=1;
	while((NowNode<<1)<=siz)
	{
		long long NextNode=NowNode<<1;
		if(NextNode+1<=siz&&heap[NextNode]>heap[NextNode+1])
		{
			NextNode++;
		}
		if(heap[NextNode]<heap[NowNode])
		{
			Sonoda::swap(heap[NextNode],heap[NowNode]);
			NowNode=NextNode;
		}
		else
		{
			break;
		}
	}
}

long long top()
{
	return heap[1];
}

long long ans;
int main()
{
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	long long N=Sonoda::read<long long>();
	for(long long i=1;i<=N;i++)
	{
		long long a=Sonoda::read<long long>();
		push(a);
	}
	while(siz!=1)
	{
		long long a=top();
		pop();
		long long b=top();
		pop();
		ans+=a*b;
		push(a+b);
	}
	printf("%lld",ans);
	return 0;
}

