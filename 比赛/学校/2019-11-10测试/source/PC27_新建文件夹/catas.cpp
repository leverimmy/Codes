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
const int MAXN=1000005;
//set <int> node;
//node.insert()
//node.size()
//set<int>::iterator it
//for(set <int>:: iterator it = node.begin();it!=node.end();it++)
//{
//	
//}
struct EDGE
{
	int _next,to;
};EDGE edge[MAXN];
int ind[MAXN],id[MAXN];
int _count,head[MAXN];
void Add_Line(const int &a,const int &b)
{
	_count++;
	edge[_count]._next=head[a];
	edge[_count].to=b;
	head[a]=_count;
}
int ans[MAXN];
void DFS(int NowNode,const int &a)
{
	for(int i=head[NowNode];i;i=edge[i]._next)
	{
		int NextNode=edge[i].to;
		ind[NextNode]--;
		if(!ind[NextNode])
		{
			ans[a]++;
			DFS(NextNode,a);
		}
	}
}

int main()
{
	freopen("catas.in","r",stdin);
	freopen("catas.out","w",stdout);
	int N=Sonoda::read<int>();
	for(int i=1;i<=N;i++)
	{
		while(1)
		{
			int a=Sonoda::read<int>();
			if(!a)
			{
				break;
			}
			Add_Line(a,i);
			id[i]++;
		}
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			ind[j]=id[j];
		}
		DFS(i,i);
	}
	for(int i=1;i<=N;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}

