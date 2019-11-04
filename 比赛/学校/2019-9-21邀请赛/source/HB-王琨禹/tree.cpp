#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
const int MAXN=100005;
const int MAXM=500005;
struct EDGE
{
	int from,to,w;
};
int head[MAXN],dis[MAXN];
struct LINE
{
	int _next,to,w;
};
LINE line[MAXM];
int _count;
void Add_EDGE(int a,int b,int c)
{
	_count++;
	line[_count]._next=head[a];
	line[_count].to=b;
	line[_count].w=c;
	head[a]=_count; 
}
EDGE edge[MAXM];
int father[MAXN];
int Find(int x)
{
	return father[x]==x?x:father[x]=Find(father[x]); 
}
void Union(int x,int y)
{
	int r1=Find(x);
	int r2=Find(y);
	if(r1!=r2)
	{
		father[r1]=r2;
	}
}
int N,M,book,ans;
bool cmp(const EDGE &a,const EDGE &b)
{
	return a.w<b.w;
}
void _Init()
{
	for(int i=1;i<=N;i++)
	{
		father[i]=i;
	}
	
}


void DFS(int NowNode,int fa)
{
	for(int i=head[NowNode];i;i=line[i]._next)
	{
		int NextNode=line[i].to;
		if(NextNode==fa)
		{
			continue;
		}
		dis[NextNode]=max(dis[NextNode],max(dis[NowNode],line[i].w));
		DFS(NextNode,NowNode);
	}
}


signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld%lld",&N,&M);
	_Init();
	for(int i=1;i<=M;i++)
	{
		int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		edge[i].from=a;
		edge[i].to=b;
		edge[i].w=c;
	}
	sort(edge+1,edge+M+1,cmp);
	for(int i=1;i<=M;i++)
	{
		int r1=Find(edge[i].from);
		int r2=Find(edge[i].to);
		if(r1!=r2)
		{
			Union(edge[i].from,edge[i].to);
			book++;
			Add_EDGE(edge[i].from,edge[i].to,edge[i].w);
			Add_EDGE(edge[i].to,edge[i].from,edge[i].w); 
		}
		if(book==N-1)
		{
			break;
		}
	}
	DFS(1,0);
	for(int i=2;i<=N;i++)
	{
		ans+=dis[i];
	}
	printf("%lld",ans);
}
