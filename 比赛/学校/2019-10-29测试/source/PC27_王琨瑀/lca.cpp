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
	int _next,to;
};
EDGE edge[MAXN];
int root;
int LastAns;
int head[MAXN],_count;
int father[MAXN][32],depth[MAXN];
void Add_Line(const int &a,const int &b)
{
	_count++;
	edge[_count].to=b;
	edge[_count]._next=head[a];
	head[a]=_count;
}
void _Init(int NowNode,int fa)
{
	depth[NowNode]=depth[fa]+1;
	father[NowNode][0]=fa;
	for(int i=1;(1<<i)<=depth[NowNode];i++)
	{
		father[NowNode][i]=father[father[NowNode][i-1]][i-1];
	}
	for(int i=head[NowNode];i;i=edge[i]._next)
	{
		int NextNode=edge[i].to;
		if(NextNode==fa)
		{
			continue;
		}
		_Init(NextNode,NowNode);
	}
}
int LCA(int a,int b)
{
	if(depth[a]<depth[b])
	{
		Sonoda::swap(a,b);
	}
	for(int i=30;i>=0;i--)
	{
		if(depth[a]-(1<<i)>=depth[b])
		{
			a=father[a][i];
		}
	}
	if(a==b)
	{
		return a;
	}
	for(int i=30;i>=0;i--)
	{
		if(father[a][i]==father[b][i])
		{
			continue;
		}
		a=father[a][i];
		b=father[b][i];
	}
	return father[a][0];
}
int main()
{
	
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	int N=Sonoda::read<int>();
	for(int i=1;i<=N;i++)
	{
		int a=Sonoda::read<int>();
		if(!a)
		{
			root=i;
		}
		else
		{
			Add_Line(a,i);
			Add_Line(i,a);
		}
	}
	_Init(root,0);
	int M=Sonoda::read<int>();
	for(int i=1;i<=M;i++)
	{
		int a=Sonoda::read<int>();
		int b=Sonoda::read<int>();
		a^=LastAns,b^=LastAns;
		LastAns=LCA(a,b);
		printf("%d\n",LastAns);
	}
	return 0;
}

