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

const int MAXN=500005;
struct EDGE
{
	int from,to,d,g;
};
EDGE edge[MAXN];
EDGE a[MAXN];
int father[MAXN];
int Find(int x)
{
	return father[x]==x?x:father[x]=Find(father[x]);
}
void Merge(int x,int y)
{
	int r1=Find(x);
	int r2=Find(y);
	if(r1!=r2)
	{
		father[r1]=r2;
	}
}
int ans=INF;
int main()
{
	freopen("pay.in","r",stdin);
	freopen("pay.out","w",stdout);
	int N=Sonoda::read<int>();
	int M=Sonoda::read<int>();
	int G=Sonoda::read<int>();
	int D=Sonoda::read<int>();
	for(int i=1;i<=M;i++)
	{
		edge[i].from=Sonoda::read<int>();
		edge[i].to=Sonoda::read<int>();
		edge[i].g=Sonoda::read<int>();
		edge[i].d=Sonoda::read<int>();
	}
	for(int i=1;i<=50;i++)
	{
		for(int j=1;j<=50;j++)
		{
			int book=0;
			for(int k=1;k<=N;k++)
			{
				father[i]=i;
			}
			for(int k=1;k<=M;k++)
			{
				if(edge[k].g>i||edge[k].d>j)
				{
					continue;
				}
				int x=edge[k].from;
				int y=edge[k].to;
				int r1=Find(x),r2=Find(y);
				if(r1!=r2)
				{
					book++;
				}
				if(book==N-1)
				{
					break;
				}
			}
			if(book==N-1)
			{
				ans=min(ans,i*G+j*D);
			}
		}
	}
	printf("%d",ans);
	return 0;
}

