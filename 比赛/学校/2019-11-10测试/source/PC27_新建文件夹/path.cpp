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
const int MAXN=2000005;
int siz[MAXN],dis[MAXN];
int ans=INF;
bool vis[MAXN];
int _array[MAXN],l,r;

struct EDGE
{
	int _next,to,w;
};
EDGE edge[MAXN];
int head[MAXN],_count;
void Add_Line(const int &a,const int &b,const int &c)
{
	_count++;
	edge[_count]._next=head[a];
	edge[_count].to=b;
	edge[_count].w=c;
	head[a]=_count;
}
int N;
int all;
int SPFA(int S)
{
	dis[S]=0;
	vis[S]=1;
	r++;
	_array[r]=S;
	while(l<r)
	{
		l++;
		int NowNode=_array[l];
		vis[NowNode]=0;
		for(int i=head[NowNode];i;i=edge[i]._next)
		{
			int NextNode=edge[i].to;
			if(dis[NextNode]>dis[NowNode]+edge[i].w)
			{
				dis[NextNode]=dis[NowNode]+edge[i].w;
				if(!vis[NextNode])
				{
					r++;
					_array[r]=NextNode;
				}
			}
		}
	}
	int now=0;
	for(int i=1;i<=N;i++)
	{
		now=max(now,dis[i]);
	}
	return now;
}
int main()
{
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	N=Sonoda::read<int>();
	for(int i=1;i<N;i++)
	{
		int a=Sonoda::read<int>();
		int b=Sonoda::read<int>();
		int c=Sonoda::read<int>();
		Add_Line(a,b,c);
		Add_Line(b,a,c);
		all+=c;
		all+=c;
	}
	for(int i=1;i<=N;i++)
	{
		int a=Sonoda::read<int>();
		if(a)
		{
			memset(dis,INF,sizeof(dis));
			memset(vis,0,sizeof(vis));
			r=0;
			l=0;
			int now=SPFA(i);
			now=all-now;
			ans=min(now,ans);
		}
	}
	printf("%d",ans);
	return 0;
}

