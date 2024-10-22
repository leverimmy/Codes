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
const int MAXN=1005;
const int MAXM=100005;
bool book[MAXM],vis[MAXN];

int head[MAXN],dis[MAXN],pre[MAXN];
int _count;
int las[MAXN];
int son[MAXN];
struct EDGE
{
	int _next,to,w;
};
EDGE edge[MAXM];

struct NODE
{
	int val,pos;
};
NODE heap[MAXN];

int siz;

void Add_Line(const int &a,const int &b,const int &c)
{
	_count++;
	edge[_count]._next=head[a];
	edge[_count].to=b;
	edge[_count].w=c;
	head[a]=_count;
}

void push(NODE a)
{
	siz++;
	heap[siz]=a;
	int NowNode=siz;
	while(NowNode>>1)
	{
		int NextNode=NowNode>>1;
		if(heap[NextNode].val>heap[NowNode].val)
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
	swap(heap[1],heap[siz]);
	siz--;
	int NowNode=1;
	while((NowNode<<1)<=siz)
	{
		int NextNode=NowNode<<1;
		if(NextNode+1<=siz&&heap[NextNode+1].val<heap[NextNode].val)
		{
			NextNode++;
		}
		if(heap[NextNode].val<heap[NowNode].val)
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

NODE top()
{
	return heap[1];
}

int main()
{
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	int N=Sonoda::read<int>();
	int M=Sonoda::read<int>();
	for(int i=1;i<=M;i++)
	{
		int a=Sonoda::read<int>();
		int b=Sonoda::read<int>();
		int c=Sonoda::read<int>();
		Add_Line(a,b,c);
		Add_Line(b,a,c);
	}
	memset(dis,INF,sizeof(dis));
	dis[1]=0;
	son[1]=1;
	push({0,1});
	while(siz)
	{
		int NowNode=top().pos;
		pop();
		if(vis[NowNode])
		{
			continue;
		}
		vis[NowNode]=true;
		for(int i=head[NowNode];i;i=edge[i]._next)
		{
			int NextNode=edge[i].to;
			if(dis[NextNode]>dis[NowNode]+edge[i].w)
			{
				dis[NextNode]=dis[NowNode]+edge[i].w;
				pre[NextNode]=NowNode;
				las[NextNode]=i;
				son[NextNode]=son[NowNode]+1;
				push({dis[NextNode],NextNode});
			}
			if(dis[NextNode]==dis[NowNode]+edge[i].w&&edge[i].w<edge[las[NextNode]].w)
			{
				pre[NextNode]=NowNode;
				las[NextNode]=i;
				son[NextNode]=son[NowNode]+1;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=N;i++)
	{
		int NowNode=i;
		while(pre[NowNode]&&!book[las[NowNode]])
		{
			book[las[NowNode]]=true;
			ans+=edge[las[NowNode]].w;
			NowNode=pre[NowNode];
		}
	}
	printf("%d",ans);
	return 0;
}

