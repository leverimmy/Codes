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
const int MAXN=400005;
struct EDGE
{
	int _next,from,to,st,en;
};EDGE edge[MAXN];
int _count,head[MAXN];
void Add_Line(const int &a,const int &b,const int &c,const int &d)
{
	_count++;
	edge[_count]._next=head[a];
	edge[_count].from=a;
	edge[_count].to=b;
	edge[_count].st=c;
	edge[_count].en=d;
	head[a]=_count;
}
int col[MAXN];
bool vis[MAXN];
bool flag;
void _Init()
{
	memset(col,-1,sizeof(col));
	memset(vis,0,sizeof(vis));
	flag=0;
}
void DFS(int NowNode,const int &T)
{
	vis[NowNode]=1;
	for(int i=head[NowNode];i;i=edge[i]._next)
	{
		if(edge[i].st<T&&edge[i].en>=T)
		{
			int NextNode=edge[i].to;
			if(col[NextNode]==col[NowNode])
			{
				flag=1;
			}
			if(!vis[NextNode])
			{
				col[NextNode]=!col[NowNode];
				DFS(NextNode,T);
			}
		}
	}
}
int main()
{
	freopen("grape.in","r",stdin);
	freopen("grape.out","w",stdout);
	int N=Sonoda::read<int>();
	int M=Sonoda::read<int>();
	int T=Sonoda::read<int>();
	for(int i=1;i<=M;i++)
	{
		int a=Sonoda::read<int>();
		int b=Sonoda::read<int>();
		int c=Sonoda::read<int>();
		int d=Sonoda::read<int>();
		Add_Line(a,b,c,d);
		Add_Line(b,a,c,d);
	}
	for(int t=1;t<=T;t++)
	{
		_Init();
		for(int i=1;i<=N;i++)
		{
			if(!vis[i])
			{
				col[i]=0;
				DFS(i,t);
			}
		}
		if(!flag)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}

